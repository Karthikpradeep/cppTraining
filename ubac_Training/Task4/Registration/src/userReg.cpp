#include "userReg.h"

userReg::userReg(string filePath):SBU2WebService(){
	this->filePath = filePath;
}

userReg::~userReg(){
}

void userReg::onInvalidJSONRequest( HTTPServerRequest * request,HTTPConnection * connection,string & rawRequest){
        cout<<"Request Recieved - "<<rawRequest<<endl;
        string id, msg,svcName,svcGroup;

        YamlConfig config1(filePath);
        id = config1["onInvalidJSON"]["id"];
        msg = config1["onInvalidJSON"]["msg"];
        svcName = config1["onInvalidJSON"]["svcName"];
        svcGroup = config1["onInvalidJSON"]["svcGroup"];

        MSFRequest *msfReq = new MSFRequest(rawRequest);
        MSFResponse *msfResp = new MSFResponse(msfReq);

        msfResp->setInfoID(id);
        msfResp->setInfoMsg(msg);
        msfResp->setSvcName(svcName);
        msfResp->setSvcGroup(svcGroup);

        sendResponse(msfResp,connection);
        connection->release();
}

void userReg::onPostProcessRequest( MSFRequest * msfrequest,MSFResponse * msfresponse, HTTPConnection *connection ){
	sqlConn sql;
	JsonObject reqJsonObj;
	JsonObject respJsonObj;
	string id,msg;
	JsonParser parser(msfrequest->toString());
	reqJsonObj = parser.getJsonObject();

	YamlConfig config2(filePath);

	string userName = reqJsonObj["username"];
	string password = reqJsonObj["password"];
	string userMail = reqJsonObj["usermail"];
	string userRole = reqJsonObj["userRole"];

	if(userName == ""|| userMail == "" || password == "" || userRole == ""){
		id = "ERROR101";
		msg = "username or usermail or password or userRole cannot be empty";
		msfresponse->setInfoID(id);
                msfresponse->setInfoMsg(msg);

		this->sendResponse(msfresponse,connection);
		
	}
	else{
		bool isAdd;
		sql.userRegister(userName,userMail,password,userRole,isAdd);
		if(isAdd){
			id = config2["onSuccessReg"]["id"];
			msg = config2["onSuccessReg"]["msg"];
		}
		else{
			id = config2["onFailReg"]["id"];
			msg = config2["onFailReg"]["msg"];
		}
		msfresponse->setInfoID(id);
		msfresponse->setInfoMsg(msg);
		this->sendResponse(msfresponse,connection);
	}
}



