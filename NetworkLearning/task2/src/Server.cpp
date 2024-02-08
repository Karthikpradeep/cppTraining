#include <iostream>
#include <vector>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>

using namespace std;

const int BUFFER_SIZE = 1024;

int main() {
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        cerr << "Error creating server socket" << endl;
        exit(EXIT_FAILURE);
    }

    sockaddr_in ServerAddress;
    ServerAddress.sin_family = AF_INET;
    ServerAddress.sin_addr.s_addr = INADDR_ANY;
    ServerAddress.sin_port = htons(8888);

    if (bind(serverSocket, (sockaddr*)&ServerAddress, sizeof(ServerAddress)) == -1) {
        cerr << "Error binding address to server socket" << endl;
        close(serverSocket);
        exit(EXIT_FAILURE);
    }

    if (listen(serverSocket, 10) == -1) {
        cerr << "Error listening for client connections" << endl;
        close(serverSocket);
        exit(EXIT_FAILURE);
    }
    cout << "Server is listening on port 8888" << endl;

    vector<int> clientSockets;
    fd_set masterSet;
    FD_ZERO(&masterSet);
    FD_SET(serverSocket, &masterSet);
    int maxFd = serverSocket;

    while (true) {
        fd_set readSet = masterSet;
        if (select(maxFd + 1, &readSet, nullptr, nullptr, nullptr) == -1) {
            cerr << "Error in select" << endl;
            close(serverSocket);
            exit(EXIT_FAILURE);
        }

        if (FD_ISSET(serverSocket, &readSet)) {
            sockaddr_in clientAddress;
            socklen_t clientSize = sizeof(clientAddress);
            int clientSocket = accept(serverSocket, (sockaddr*)&clientAddress, &clientSize);
            if (clientSocket == -1) {
                cerr << "Error accepting client connection" << endl;
            } else {
                cout << "New connection from " << inet_ntoa(clientAddress.sin_addr)
                     << " on socket " << clientSocket << endl;
                clientSockets.push_back(clientSocket);
                FD_SET(clientSocket, &masterSet);
                maxFd = max(maxFd, clientSocket);
            }
        }

        for (int i = 0; i < clientSockets.size(); ++i) {
            int clientSocket = clientSockets[i];
            if (FD_ISSET(clientSocket, &readSet)) {
                char buffer[BUFFER_SIZE];
                memset(buffer, 0, BUFFER_SIZE);

                ssize_t bytesRead = recv(clientSocket, buffer, sizeof(buffer), 0);
                if (bytesRead <= 0) {
                    if (bytesRead == 0) {
                        cout << "Client on socket " << clientSocket << " disconnected." << endl;
                    } else {
                        cerr << "Error receiving data from client on socket " << clientSocket << endl;
                    }

                    close(clientSocket);
                    FD_CLR(clientSocket, &masterSet);
                    clientSockets.erase(clientSockets.begin() + i);
                    --i;
                } else {
                    for (int j = 0; j < clientSockets.size(); ++j) {
                        int otherClientSocket = clientSockets[j];
                        if (otherClientSocket != clientSocket) {
                            ssize_t bytesSent = send(otherClientSocket, buffer, bytesRead, 0);
                            if (bytesSent == -1 || bytesSent < bytesRead) {
                                cerr << "Error sending message to client on socket " << otherClientSocket << endl;
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}

