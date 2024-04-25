#include "answerPortal.h"

answerPortal::answerPortal(string filePath):SBU2WebService(){
        this->filePath = filePath;
}

answerPortal::~answerPortal(){
}

void answerPortal::onInvalidJSONRequest( HTTPServerRequest * request,HTTPConnection * connection,string & rawRequest){
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

void answerPortal::onPostProcessRequest( MSFRequest * msfrequest,MSFResponse * msfresponse, HTTPConnection *connection ){
        sqlConn sql;
        JsonObject reqJsonObj;
        JsonObject respJsonObj;
        string id,msg;
        JsonParser parser(msfrequest->toString());
        reqJsonObj = parser.getJsonObject();

        YamlConfig config2(filePath);

        MYSQL_RES *mResult;
        string sError;
        uint64_t nID;
	
	

        string sessId = reqJsonObj["sessionId"];
	string userName = reqJsonObj["username"];
	string questNum = reqJsonObj["questionNumber"];
	string ans = reqJsonObj["answer"];

        if(sessId == "" || userName == "" || questNum == "" || ans == ""){
                id = "Error101";
                msg = "Session id or username or question number or answer cannot be empty";
                msfresponse->setInfoID(id);
                msfresponse->setInfoMsg(msg);
        }
	else{
		bool isSValid;
		sql.isSessionValid(sessId,isSValid);
		if(isSValid){
			bool resp = sql.setAnswer(userName,questNum,ans);
			if(resp){
				cout<<"Answer stored successfully"<<endl;
				respJsonObj["questionNumber"] = questNum;
				respJsonObj["answer"] = ans;
				msfresponse->setInfoID("exe101");
			        msfresponse->setInfoMsg("Successfully stored the answer");
				msfresponse->addToData(respJsonObj);
			}
			else{
				cout<<"Answer cannot be  stored"<<endl;
                           
                                msfresponse->setInfoID("ERROR401");
                                msfresponse->setInfoMsg("failed to store the answer");
                        }
		}
		else{
			msfresponse->setInfoMsg("Invalid Session");
                        msfresponse->setInfoID("Error 401");
		}
	}
	 this->sendResponse(msfresponse,connection);
        connection->release();
}


