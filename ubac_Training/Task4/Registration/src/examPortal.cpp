#include "examPortal.h"

examPortal::examPortal(string filePath):SBU2WebService(){
        this->filePath = filePath;
}

examPortal::~examPortal(){
}

void examPortal::onInvalidJSONRequest( HTTPServerRequest * request,HTTPConnection * connection,string & rawRequest){
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

void examPortal::onPostProcessRequest( MSFRequest * msfrequest,MSFResponse * msfresponse, HTTPConnection *connection ){
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

	if(sessId == "" ){
		id = "Error101";
		msg = "Session id cannot be empty";
		msfresponse->setInfoID(id);
		msfresponse->setInfoMsg(msg);
	}
	else{
		bool isSValid;
		sql.isSessionValid(sessId,isSValid);
		if(isSValid){
			 respJsonObj = sql.getQuestions(sessId);
			 msfresponse->setInfoID("exe101");
			 msfresponse->setInfoMsg("Success");
			 msfresponse->addToData("Questions",respJsonObj);
		}
		else{
			msfresponse->setInfoMsg("Invalid Session");
			msfresponse->setInfoID("Error 401");
		}
	}
	this->sendResponse(msfresponse,connection);
	connection->release();
}
