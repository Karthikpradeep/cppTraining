#include <serverHeader.h>

int main() {
    ServerNetworkHandler serverHandler;
    serverHandler.setupServer();
    serverHandler.handleServerConnections();

    return 0;
}

