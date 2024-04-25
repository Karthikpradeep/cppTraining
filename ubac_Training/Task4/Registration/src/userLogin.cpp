#include "userLogin.h"

userLogin::userLogin(string filePath):SBU2WebService(){
        this->filePath = filePath;
}

userLogin::~userLogin(){
}

void userLogin::onInvalidJSONRequest( HTTPServerRequest * request,HTTPConnection * connection,string & rawRequest){
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

void userLogin::onPostProcessRequest( MSFRequest * msfrequest,MSFResponse * msfresponse, HTTPConnection *connection ){
        sqlConn sql;
        JsonObject reqJsonObj;
        JsonObject respJsonObj;
        string id,msg;
        JsonParser parser(msfrequest->toString());
        reqJsonObj = parser.getJsonObject();

        YamlConfig config2(filePath);
	
	string sId;

	string userName = reqJsonObj["username"];
        string password = reqJsonObj["password"];

	if(userName == ""|| password == ""){
                id = "ERROR101";
                msg = "Username or password cannot be empty";
                msfresponse->setInfoID(id);
                msfresponse->setInfoMsg(msg);

                this->sendResponse(msfresponse,connection);
        }

	else{
		bool isValid;
		sql.isValidUser(userName,password,isValid);
		if(isValid){
			sId = sql.createSessionId();
			
			bool isSbegin;
			sql.sessionBegin(userName,sId,isSbegin);
			if(isSbegin){
				respJsonObj["message"] = sId;
				msfresponse->addToData(respJsonObj);
				id = "101";
				msg = "Login successfull";
			}
			else{
				id = "Err 401";
				msg = "You are already logged in ";
			}
		}
		else{
			id = "Error 404";
			msg = "Invalid userName or Password";
		}
	}

	msfresponse->setInfoID(id);
        msfresponse->setInfoMsg(msg);
	this->sendResponse(msfresponse,connection);
	connection->release();
}


					
	


