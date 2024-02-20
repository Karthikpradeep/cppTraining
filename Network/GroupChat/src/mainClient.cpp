#include <clientHeader.h>

int main() {
    ClientNetworkHandler clientHandler;
    clientHandler.setupClient();
    clientHandler.connectToServer();
    clientHandler.handleCommunication();

    return 0;
}

