#include <headers.h>

using namespace std;

const int BUFFER_SIZE = 1024;

int main() {
    // Client socket creation
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        perror("!!! Error creating client socket !!!");
        exit(EXIT_FAILURE);
    }

    // Server configuration
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8888);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &serverAddress.sin_addr) <= 0) {
        perror("Invalid address/ Address not supported");
        exit(EXIT_FAILURE);
    }

    // Connection to the server
    if (connect(client_socket, (sockaddr*)&serverAddress, sizeof(serverAddress)) == -1) {
        perror("!!! Error while connecting to the server !!!");
        close(client_socket);
        exit(EXIT_FAILURE);
    }

    cout << "......Connected to the server......" << endl;

    fd_set rset;
    char buffer[BUFFER_SIZE]; // buffer for data received from the server
    char str[1024]; // user name
    cout << "Enter your name: ";
    cin >> str;
    strcat(str, "> ");
    char strname[BUFFER_SIZE];

    // Send the user name to the server
    send(client_socket, str, strlen(str), 0);

    while (true) {
        FD_ZERO(&rset);
        FD_SET(0, &rset); // Add stdin (user input) to the set
        FD_SET(client_socket, &rset); // Add the client socket to the set

        select(client_socket + 1, &rset, NULL, NULL, NULL);

        if (FD_ISSET(0, &rset)) {
            // User input is ready
            fgets(buffer, BUFFER_SIZE, stdin);
            // Send user name along with the data to the server
            memset(strname, 0, BUFFER_SIZE);
            strcat(strname, str);
            buffer[strcspn(buffer, "\n")] = 0;
            if (strlen(buffer) != 0) {
                strcat(strname, buffer);
                send(client_socket, strname, strlen(strname), 0);
	
            }
        }

        if (FD_ISSET(client_socket, &rset)) {
            // Data from the server is ready
            memset(buffer, 0, BUFFER_SIZE);
            // Handle data received from the server
            if (read(client_socket, buffer, BUFFER_SIZE) <= 0) {
                // Handle disconnection or error
                cerr << "Server disconnected or error occurred." << endl;
                break;
            }
            buffer[strcspn(buffer, "\n")] = 0;
            cout << buffer << endl;
        }
    }

    close(client_socket);
    return 0;
}

