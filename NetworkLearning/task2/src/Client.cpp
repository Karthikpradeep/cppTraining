	#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <vector>

using namespace std;

int main() {
    // Create a socket
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == -1) {
        cerr << "Error creating a socket" << endl;
        exit(EXIT_FAILURE);
    }

    // Connect to the server address
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8888);  // Server port
    inet_pton(AF_INET, "127.0.0.1", &serverAddress.sin_addr);  // Server IP address

    if (connect(clientSocket, (sockaddr*)(&serverAddress), sizeof(serverAddress)) == -1) {
        cerr << "Error while connecting to the server" << endl;
        exit(EXIT_FAILURE);
    }

    cout << "Connected to the server" << endl;

    fd_set masterSet;
    FD_ZERO(&masterSet);
    FD_SET(clientSocket, &masterSet);

    string userName;
    cout << "Enter your name: ";
    cin >> userName;
    userName += "> ";

    while (true) {
        fd_set rset = masterSet;

        if (select(clientSocket + 1, &rset, NULL, NULL, NULL) == -1) {
            cerr << "Error in select" << endl;
            close(clientSocket);
            exit(EXIT_FAILURE);
        }

        if (FD_ISSET(clientSocket, &rset)) {
            // Data from the server is ready
            char buffer[1024];
            memset(buffer, 0, sizeof(buffer));

            // Handle data received from the server
            ssize_t bytesRead = recv(clientSocket, buffer, sizeof(buffer), 0);
            if (bytesRead <= 0) {
                // Handle disconnection or error
                cerr << "Server disconnected or error occurred." << endl;
                break;
            }

            buffer[bytesRead] = '\0'; // Ensure null-termination
            cout << buffer << endl;
        }

        // User input is ready
        string message;
        cin.ignore();  // Clear the input buffer
        cout << "Enter your message: ";
        getline(cin, message);

        if (!message.empty()) {
            string strname = userName + message;
            send(clientSocket, strname.c_str(), strname.size(), 0);
        }
    }

    close(clientSocket);
    return 0;
}

