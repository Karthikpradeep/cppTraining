#ifndef SERVERHEADER_H
#define SERVERHEADER_H

#include <iostream>
#include <unistd.h>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

class ServerNetworkHandler {
public:
    static const int MAX_CLIENTS =10;
    static const int BUFFER_SIZE = 1024;
    ServerNetworkHandler();
    ~ServerNetworkHandler();

    void setupServer();
    void handleServerConnections();

private:
    int serverSocket;
    int clientSockets[MAX_CLIENTS];
    char buffer[BUFFER_SIZE] = {0}; 
    fd_set masterSet;
    int maxFd;
};

#endif

