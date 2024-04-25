#include "searchHeader.h"
#include "detailHeader.h"
#include "setHeader.h"

int main(int argc, char** argv){
	if(argc != 2){
		cout<<"!!! Wrong format !!!"<<endl;
		cout<<"./obj ./Config/conf.yaml is the correct format"<<endl;
		return 1;
	}

	string ConFile(argv[1]);

	YamlConfig config(ConFile);
	SetDetails *SetServer = new SetDetails(ConFile);
	SearchEmployee *SearchServer = new SearchEmployee(ConFile);
	GetDetails *GetServer = new GetDetails(ConFile);	
	map<string, SBU2WebService*> *langWebService = new map<string, SBU2WebService*>;
        string setEndUrl = config["SetDetails"]["endUrl"];
	string searchEndUrl = config["SearchDetails"]["endUrl"];
	string getEndUrl = config["GetDetails"]["endUrl"];

	langWebService->insert(make_pair(setEndUrl,SetServer));
	langWebService->insert(make_pair(searchEndUrl,SearchServer));
	langWebService->insert(make_pair(getEndUrl,GetServer));

	string loadBalance = config["ConnectionDetails"]["load"];
	int lb = stoi(loadBalance);
	SBU2LoadBalancer *loadBalancer = new SBU2LoadBalancer(lb,langWebService);

	string portnum = config["ConnectionDetails"]["port"];
	int port = stoi(portnum);

	SBU2HTTPServer *ServerObj = new SBU2HTTPServer(port,loadBalancer);
	ServerObj->run();
	while(1);
}
