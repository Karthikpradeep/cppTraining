#include "adminPortal.h"

adminPortal::adminPortal(string filePath):SBU2WebService(){
	this->filePath = filePath;
}

adminPortal::~adminPortal(){
}

void adminPortal::onInvalidJSONRequest( HTTPServerRequest * request,HTTPConnection * connection,string & rawRequest){
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

void adminPortal::onPostProcessRequest( MSFRequest * msfrequest,MSFResponse * msfresponse, HTTPConnection *connection ){
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
	string password = reqJsonObj["password"];
	string val = reqJsonObj["value"];

	if(sessId == "" || userName == "" || password == "" || val ==""){
		id = "Error101";
		msg = "Session id or username or question number or answer or value cannot be empty";
		msfresponse->setInfoID(id);
		msfresponse->setInfoMsg(msg);
	}
	else{
		bool isSValid;
		bool userCheck = sql.checkUser(userName);
		sql.isSessionValid(sessId,isSValid);
		if(isSValid){
			if(!userCheck){
				msfresponse->setInfoID("ErrorUser");
				msfresponse->setInfoMsg("User have no admin privilages");
			}
			else{
				if(val == "rank"){
					respJsonObj = sql.getRankList();

					msfresponse->setInfoID("exe101");
					msfresponse->setInfoMsg("");
					msfresponse->addToData(respJsonObj);
				}
				else if(val == "failed"){
					respJsonObj = sql.getGradeList("D");
					msfresponse->setInfoID("exe101");
					msfresponse->setInfoMsg("Success");
					msfresponse->addToData(respJsonObj);
				}
				else if(val == "gradeList"){
					string grade = reqJsonObj["grade"];
					if(grade == ""){
						id = "Error101";
						msg = "grade cannot be empty";
						msfresponse->setInfoID(id);
						msfresponse->setInfoMsg(msg);
					}
					else{

						respJsonObj = sql.getGradeList(grade);
						msfresponse->addToData(respJsonObj);
					}

				}
				else{
					respJsonObj["message"] = "Invalid value for value";
					msfresponse->addToData(respJsonObj);
				}
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

