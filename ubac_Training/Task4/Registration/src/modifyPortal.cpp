#include "modifyPortal.h"

modifyPortal::modifyPortal(string filePath):SBU2WebService(){
	this->filePath = filePath;
}

modifyPortal::~modifyPortal(){
}

void modifyPortal::onInvalidJSONRequest( HTTPServerRequest * request,HTTPConnection * connection,string & rawRequest){
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

void modifyPortal::onPostProcessRequest( MSFRequest * msfrequest,MSFResponse * msfresponse, HTTPConnection *connection ){
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
	string action = reqJsonObj["action"];

	if(sessId == "" || userName == ""){
		id = "Error101";
		msg = "Session id or username or question number or answer cannot be empty";
		msfresponse->setInfoID(id);
		msfresponse->setInfoMsg(msg);
	}
	else{
		bool isSValid;
		sql.isSessionValid(sessId,isSValid);
		if(isSValid){
			if(action == "modify"){
				if(questNum == "" || ans == ""){
					id = "Error101";
					msg = "question number or answer cannot be empty";
					msfresponse->setInfoID(id);
					msfresponse->setInfoMsg(msg);

				}else{

					bool resp = sql.modifyAnswer(userName,questNum,ans);
					if(resp){
						cout<<"Answer modified successfully"<<endl;
						respJsonObj["questionNumber"] = questNum;
						respJsonObj["answer"] = ans;
						msfresponse->setInfoID("exe101");
						msfresponse->setInfoMsg("Successfully modified the answer");
						msfresponse->addToData(respJsonObj);
					}
					else{
						cout<<"Answer cannot be modified"<<endl;

						msfresponse->setInfoID("ERROR401");
						msfresponse->setInfoMsg("failed to modify the answer");
					}
				}
			}
			else if(action == "review"){
				respJsonObj = sql.reviewResponse(userName);
				msfresponse->setInfoID("exe101");
				msfresponse->setInfoMsg("Success");
				msfresponse->addToData("Questions",respJsonObj);
			}
			else if(action == "finish"){
				int totalMarks = sql.calculateMarks(userName);	
				string grade = determineGrade(totalMarks);
				respJsonObj["totalMark"] = totalMarks;
				respJsonObj["grade"] = grade;

				bool resp = sql.setGrade(userName,grade);
				if(resp){
					cout<<"Grade added successfully"<<endl;
					respJsonObj["Grade - "] = grade;
					msfresponse->setInfoID("exe101");
					msfresponse->setInfoMsg("Successfully added grade");
					msfresponse->addToData(respJsonObj);
				}
				else{
					cout<<"grade cannot be added"<<endl;

					msfresponse->setInfoID("ERROR401");
					msfresponse->setInfoMsg("failed to add grade");
				}

			}
			else{
				msfresponse->setInfoMsg("Invalid Session");
				msfresponse->setInfoID("Error 401");
			}
		}
	}
	this->sendResponse(msfresponse,connection);
	connection->release();
}

string modifyPortal::determineGrade(int totalMarks) {
	if (totalMarks >= 0 && totalMarks <= 10) {
		return "D";
	} else if (totalMarks > 10 && totalMarks <= 20) {
		return "C";
	} else if (totalMarks > 20 && totalMarks <= 30) {
		return "B";
	} else if (totalMarks > 30) {
		return "A";
	} else {
		return "F";
	}
}

