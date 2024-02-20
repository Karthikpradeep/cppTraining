#ifndef CLIENTHEADER_H
#define CLIENTHEADER_H

#include <iostream>
#include <unistd.h>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

class ClientNetworkHandler {
public:
    ClientNetworkHandler();
    ~ClientNetworkHandler();

    void setupClient();
    void connectToServer();
    void handleCommunication();

private:
    static const int BUFFER_SIZE = 1024;
    int clientSocket;
};

#endif

