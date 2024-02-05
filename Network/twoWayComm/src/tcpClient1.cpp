#include<common.h>

using namespace std;

int main(){
	//create a socket

	int clientSocket = socket(AF_INET,SOCK_STREAM,0);
	if(clientSocket == -1){
		cerr<<"!!! Error creating a socket !!!"<<endl;
		exit(EXIT_FAILURE);
	}

	//connect to server address
	sockaddr_in serverAddress;
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_port = htons(8888);//server port
	inet_pton(AF_INET,"0.0.0.0",&serverAddress.sin_addr); //server ip address

	if(connect(clientSocket,(sockaddr*)(&serverAddress),sizeof(serverAddress)) == -1){
		cerr<<"!!! Error while connection to server !!!"<<endl;
		exit(EXIT_FAILURE);
	}

	cout<<"......Connected to server ......"<<endl;

	//send data to server
	while(true){
		const int bufferSize = 1024;
		char message[bufferSize];
		cout<<"Enter message to sent to server - ";
		cin.getline(message,bufferSize);
		if(strcmp(message,"bye") == 0){
			cout<<"Client Exiting"<<endl;
			send(clientSocket,message,strlen(message),0);
			close(clientSocket);
			exit(EXIT_SUCCESS);
		}
		ssize_t bytesSent = send(clientSocket,message,strlen(message),0);
		if (bytesSent == -1){
			cout<<"!!! Error while sending data to server !!!"<<endl;
			exit(EXIT_FAILURE);
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
	}
	//close socket
	close(clientSocket);

	return 0;
}

