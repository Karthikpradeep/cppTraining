#include <webHeader.h>

int main(int argc, char** argv){
	if(argc != 3){
		cout<<"!!! Wrong format !!!"<<endl;
		cout<<"./obj ./data/filename.json ./config/conf.yaml is the correct format"<<endl;
		return 1;
	}
	string path(argv[1]);
	string ConFile(argv[2]);
	
	YamlConfig config(ConFile);
	HTTPwebService *httpServer = new HTTPwebService(path,ConFile);

        map<string, SBU2WebService*> *langWebService = new map<string, SBU2WebService*>;
	string endUrl = config["httpServer"]["endUrl"];

	langWebService->insert(make_pair(endUrl,httpServer));

	string loadBalance = config["httpServer"]["load"];
	int lb = stoi(loadBalance);
	SBU2LoadBalancer *loadBalancer = new SBU2LoadBalancer(lb,langWebService);

	string portnum = config["httpServer"]["port"];
	int port = stoi(portnum);

	SBU2HTTPServer *httpServerObj = new SBU2HTTPServer(port,loadBalancer);

	httpServerObj->run();
	while(1);
}

