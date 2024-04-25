#include "userLogout.h"

userLogout::userLogout(string filePath):SBU2WebService(){
        this->filePath = filePath;
}

userLogout::~userLogout(){
}

void userLogout::onInvalidJSONRequest( HTTPServerRequest * request,HTTPConnection * connection,string & rawRequest){
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

        this->sendResponse(msfResp,connection);
        connection->release();
}

void userLogout::onPostProcessRequest( MSFRequest * msfrequest,MSFResponse * msfresponse, HTTPConnection *connection ){
        sqlConn sql;
        JsonObject reqJsonObj;
        JsonObject respJsonObj;
        string id,msg;
        JsonParser parser(msfrequest->toString());
        reqJsonObj = parser.getJsonObject();

        YamlConfig config2(filePath);

        string sId;

        string userName = reqJsonObj["username"];
        string sessionId = reqJsonObj["sessionId"];

	if(sessionId == ""){
		id = "Error401";
		msg = "Session failed";
	}
	else if(userName == ""){
			id = "Error404";
			msg = "Required data insufficient ";
		}
	else{
		bool isSValid;
		sql.isSessionValid(sessionId,isSValid);
		if(isSValid){
			bool isLogOut;
			sql.userLogOut(sessionId,isLogOut);
			if(isLogOut)
			{
				respJsonObj["message"] = "User logged out";
				msfresponse->addToData(respJsonObj);
				id = "Success 101";
				msg = "User successfully logged out";
			}
			else{
				id = "ERR401";
				msg = "Logout Error";
			}
		}
		else{
			id = "Error 101";
			msg = "Invalid session";
		}
	}
	msfresponse->setInfoID(id);
	msfresponse->setInfoMsg(msg);
	this->sendResponse(msfresponse,connection);
	connection->release();
}






