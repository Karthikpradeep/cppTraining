
#include <clientHeader.h>

ClientNetworkHandler::ClientNetworkHandler() : clientSocket(-1) {}

ClientNetworkHandler::~ClientNetworkHandler() {
}

void ClientNetworkHandler::setupClient() {
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == -1) {
        perror("!!! Error creating client socket !!!");
        exit(EXIT_FAILURE);
    }
}

void ClientNetworkHandler::connectToServer() {
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8888);

    if (inet_pton(AF_INET, "127.0.0.1", &serverAddress.sin_addr) <= 0) {
        perror("Invalid address/ Address not supported");
        exit(EXIT_FAILURE);
    }

    if (connect(clientSocket, (sockaddr*)&serverAddress, sizeof(serverAddress)) == -1) {
        perror("!!! Error while connecting to the server !!!");
        close(clientSocket);
        exit(EXIT_FAILURE);
    }

    std::cout << "......Connected to the server......" << std::endl;
}

void ClientNetworkHandler::handleCommunication() {
    fd_set rset;
    char buffer[BUFFER_SIZE];
    char str[1024];
    std::cout << "Enter your name: ";
    std::cin >> str;
    strcat(str, "> ");
    char strname[BUFFER_SIZE];

    send(clientSocket, str, strlen(str), 0);
    std::cout << "Type bye to exit the group chat" << std::endl;

    while (true) {
        FD_ZERO(&rset);
        FD_SET(0, &rset); 
        FD_SET(clientSocket, &rset); // Add the client socket to the set

        select(clientSocket + 1, &rset, NULL, NULL, NULL);

        if (FD_ISSET(0, &rset)) {
            // User input is ready
            fgets(buffer, BUFFER_SIZE, stdin);
            memset(strname, 0, BUFFER_SIZE);
            strcat(strname, str);
            buffer[strcspn(buffer, "\n")] = 0;
            if (strlen(buffer) != 0) {
                strcat(strname, buffer);
                send(clientSocket, strname, strlen(strname), 0);
                if(strcmp(buffer, "bye") == 0){
                    exit(EXIT_SUCCESS);
                }
            }
        }

        if (FD_ISSET(clientSocket, &rset)) {
            // Data from the server is ready
            memset(buffer, 0, BUFFER_SIZE);
            if (read(clientSocket, buffer, BUFFER_SIZE) <= 0) {
                std::cerr << "Server disconnected or error occurred." << std::endl;
                break;
            }
            buffer[strcspn(buffer, "\n")] = 0;
            std::cout << buffer << std::endl;
        }
    }

    close(clientSocket);
}

