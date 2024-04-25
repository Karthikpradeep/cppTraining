#include "sqlConn.h"
#include "userReg.h"
#include "userLogin.h"
#include "userLogout.h"
#include "examPortal.h"
#include "answerPortal.h"
#include "modifyPortal.h"
#include "adminPortal.h"

int main(int argc,char** argv){
	if(argc != 2){
		cerr<<"!!! Wrong format !!!"<<endl;
		cerr<<"./obj ./config/conf.yaml is the correct format "<<endl;
	}

	string conFile(argv[1]);
	YamlConfig config(conFile);

	userReg *regServer = new userReg(conFile);
	userLogin *loginServer = new userLogin(conFile);
	userLogout *logoutServer = new userLogout(conFile);
	examPortal *examServer = new examPortal(conFile);
	answerPortal *answerServer = new answerPortal(conFile);
	modifyPortal *modifyServer = new modifyPortal(conFile);
	adminPortal *adminServer = new adminPortal(conFile);

	sqlConn *sq = new sqlConn();
	string hName = config["DatabaseDetails"]["ip"];
	string usr = config["DatabaseDetails"]["user"];
	string pswd = config["DatabaseDetails"]["password"];
	string db = config["DatabaseDetails"]["database"];

	sq->DBConn(hName,usr,pswd,db);

	map<string, SBU2WebService*> *RegWebService = new map<string, SBU2WebService*>;
	string regUrl = config["registration"]["userReg"];
	string logUrl = config["registration"]["userLog"];
	string logOutUrl = config["registration"]["userLogOut"];
	string examUrl = config["ExamDetals"]["startExam"];
	string ansUrl = config["ExamDetals"]["answerService"];
	string modifyUrl = config["ExamDetals"]["modifyServ"];
	string adminUrl = config["adminUrl"];

	RegWebService->insert(make_pair(regUrl,regServer));
	RegWebService->insert(make_pair(logUrl,loginServer));
	RegWebService->insert(make_pair(logOutUrl,logoutServer));
	RegWebService->insert(make_pair(examUrl,examServer));
	RegWebService->insert(make_pair(ansUrl,answerServer));
	RegWebService->insert(make_pair(modifyUrl,modifyServer));
	RegWebService->insert(make_pair(adminUrl,adminServer));


	string loadBalance = config["ConnectionDetails"]["load"];
	int lb = stoi(loadBalance);

	SBU2LoadBalancer *loadBalancer = new SBU2LoadBalancer(lb,RegWebService);

	string portNum = config["ConnectionDetails"]["port"];
	int port = stoi(portNum);

	SBU2HTTPServer *ServerObj = new SBU2HTTPServer(port,loadBalancer);
	ServerObj->run();
	while(1);
}
	

