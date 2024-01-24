#include<iostream>
#include<cstring>
#include<unistd.h>
#include<arpa/inet.h>

using namespace std;

int main(){
	//create a socket
	
	int clientSocket = socket(AF_INET,SOCK_STREAM,0);
	if(clientSocket == -1){
		cerr<<"!!! Error creating a socket !!!"<<endl;
		return -1;
	}

	//connect to server address
	sockaddr_in serverAddress;
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_port = htons(8888);//server port
	inet_pton(AF_INET,"0.0.0.0",&serverAddress.sin_addr); //server ip address

	if(connect(clientSocket,(sockaddr*)(&serverAddress),sizeof(serverAddress)) == -1){
		cerr<<"!!! Error while connection to server !!!"<<endl;
		return -1;
	}

	cout<<"......Connected to server ......"<<endl;

	//send data to server
	const char* message = "Hello from client";
	ssize_t bytesSent = send(clientSocket,message,strlen(message),0);
	if (bytesSent == -1){
		cout<<"!!! Error while sending data to server !!!"<<endl;
		return -1;
	}
	
	//receive response from server
	char buffer[1024];
	ssize_t byteRead = recv(clientSocket, buffer,sizeof(buffer),0);
	if(byteRead == -1){
		cerr<<"!!! Error receiving response from server !!!"<<endl;
	}
	else{
		buffer[byteRead]='\0';
		cout<<"Received response from server - "<<buffer<<endl;
	}
	//close socket
	close(clientSocket);

	return 0;
}


