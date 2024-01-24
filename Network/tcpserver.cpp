#include<iostream>
#include<cstring>
#include<unistd.h>
#include<arpa/inet.h>

using namespace std;

int main(){
	
	// Create a socket
	
	int serverSocket = socket(AF_INET,SOCK_STREAM,0);
	if(serverSocket == -1){
		cerr<<"!!! Error while creating socket !!!"<<endl;
		return -1;
	}

	// Bind socket to a specific address and port
	sockaddr_in serverAddress;
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_addr.s_addr = INADDR_ANY;
	serverAddress.sin_port = htons(8888);

	if(bind(serverSocket, (sockaddr*) (&serverAddress), sizeof(serverAddress)) == -1){
		cerr<<"Error occured while binding socket"<<endl;
		close(serverSocket);
		return -1;
	}

	//listen for incoming connection
	if(listen(serverSocket,5) == -1){
		cerr<<"!!! Error listening for connection !!!"<<endl;
		return -1;
	}
	cout<<"......Server listening on port 8888......"<<endl;

	//Accepts the client connection
	sockaddr_in clientAddress;
	socklen_t clientAddrSize  = sizeof(clientAddress);
	int clientSocket = accept(serverSocket, (sockaddr*) (&clientAddress), &clientAddrSize);
	if(clientSocket == -1){
		cerr<<"!!! Error Accepting client !!!"<<endl;
		close(serverSocket);
		return -1;
	}
	cout<<"......Connection established with client......"<<endl;

	//Receive data from client
	char buffer[1024];
	ssize_t bytesRead = recv(clientSocket,buffer, sizeof(buffer),0);
	if (bytesRead == -1){
		cerr<<"!!! Error receiving data from client !!!"<<endl;
	}
	else{
		buffer[bytesRead] = '\0';
		cout<<"Received message from client - "<<buffer<<endl;
		//send response to client
		const char* response = "Hello from server";
		ssize_t byteSent = send(clientSocket, response, strlen(response),0);
		if(byteSent == -1){
			cerr<<"!!!Error while sending response to client !!!"<<endl;
		}
	}
	//closing sockets
	close(clientSocket);
	close(serverSocket);

	return 0;
		
}

