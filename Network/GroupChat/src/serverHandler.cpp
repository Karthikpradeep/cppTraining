#include <serverHeader.h>

using namespace std;
ServerNetworkHandler::ServerNetworkHandler() : serverSocket(-1), maxFd(-1) {
    FD_ZERO(&masterSet);
    for (int i = 0; i < MAX_CLIENTS; ++i) {
        clientSockets[i] = 0;
    }
}

ServerNetworkHandler::~ServerNetworkHandler() {
   
}

void ServerNetworkHandler::setupServer() {
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        perror("!!! Error creating server socket !!!");
        exit(EXIT_FAILURE);
    }

    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(8888);

    if (bind(serverSocket, (sockaddr*)&serverAddress, sizeof(serverAddress)) == -1) {
        perror("!!! Binding Failed !!!");
        exit(EXIT_FAILURE);
    }

    if (listen(serverSocket, MAX_CLIENTS) == -1) {
        perror("!!! Listen failed !!!");
        exit(EXIT_FAILURE);
    }

    cout << "......Server listening to the port 8888......" << endl;

    FD_SET(serverSocket, &masterSet);
    maxFd = serverSocket;
}

void ServerNetworkHandler::handleServerConnections() {
       while (true) {
        fd_set readSet = masterSet;
        if (select(maxFd + 1, &readSet, nullptr, nullptr, nullptr) < 0) {
            perror("!!! Select failed !!!");
            exit(EXIT_FAILURE);
        }

        if (FD_ISSET(serverSocket, &readSet)) {
            sockaddr_in clientAddress;
            socklen_t clientSize = sizeof(clientAddress);
            int clientSocket = accept(serverSocket, (sockaddr*)&clientAddress, &clientSize);
            if (clientSocket == -1) {
                perror("!!! Error while accepting connection !!!");
                exit(EXIT_FAILURE);
            }

            for (int i = 0; i < MAX_CLIENTS; ++i) {
                if (clientSockets[i] == 0) {
                    clientSockets[i] = clientSocket;
                    FD_SET(clientSocket, &masterSet);
                    if (clientSocket > maxFd) {
                        maxFd = clientSocket;
                    }
                    break;
                }
            }
            cout << "......New Client Connected......" << endl;
        }

        for (int i = 0; i < MAX_CLIENTS; ++i) {
                    if (clientSockets[i] > 0 && FD_ISSET(clientSockets[i], &readSet)) {	//check if there is data to be read from that client
                memset(buffer, 0, BUFFER_SIZE);// clear the buffer 

                // Receive data from the client
                ssize_t bytesRead = read(clientSockets[i], buffer, BUFFER_SIZE);//reads data from client socket to buffer
                if (bytesRead <= 0) {
                    // Handle disconnection or error
                    cout << "......Client disconnected......" << endl;
                    close(clientSockets[i]);
                    FD_CLR(clientSockets[i], &masterSet);//client socket is cleared from masterSet
                    clientSockets[i] = 0;
                } else {
                    // Broadcast the received data to all other clients
                    for (int j = 0; j < MAX_CLIENTS; ++j) {
                        if (clientSockets[j] > 0 && clientSockets[j] != clientSockets[i]) {
                            send(clientSockets[j], buffer, static_cast<size_t>(bytesRead), 0);//send data to other clients
                        }
                    }
                }
            }
        }
    }
    
    close(serverSocket);
   
}

