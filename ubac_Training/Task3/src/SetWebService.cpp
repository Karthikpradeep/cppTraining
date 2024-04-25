#include "setHeader.h"

SetDetails::SetDetails(const string& filePath):SBU2WebService(){
	this->filePath = filePath;
}

SetDetails::~SetDetails(){
	delete mysqlConnection;
}

void SetDetails::onInvalidJSONRequest( HTTPServerRequest * request,HTTPConnection * connection,string & rawRequest){
	cout<<"Request Recieved - "<<rawRequest<<endl;
	string id, msg,svcName,svcGroup;

	YamlConfig config1(filePath);
	id = config1["onInvalidJson"]["id"];
	msg = config1["onInvalidJson"]["msg"];
	svcName = config1["onInvalidJson"]["svcName"];
	svcGroup = config1["onInvalidJson"]["svcGroup"];

	MSFRequest *msfReq = new MSFRequest(rawRequest);
	MSFResponse *msfResp = new MSFResponse(msfReq);

	msfResp->setInfoID(id);
	msfResp->setInfoMsg(msg);
	msfResp->setSvcName(svcName);
	msfResp->setSvcGroup(svcGroup);

	sendResponse(msfResp,connection);
	connection->release();
}

void SetDetails::onPostProcessRequest( MSFRequest * msfrequest,MSFResponse * msfresponse, HTTPConnection *connection ){
	JsonObject reqJsonObj;
	JsonObject respJsonObj;
	
	YamlConfig config2(filePath);

	mysqlConnection = new UBACSql(config2["DatabaseDetails"]["ip"],config2["DatabaseDetails"]["user"],config2["DatabaseDetails"]["password"],config2["DatabaseDetails"]["Database"]);
        MYSQL_RES *mResult;
        uint64_t nID;

	cout<<"In myWebService on post request "<<endl;
	cout<<"Request received - "<<msfrequest->toString()<<endl;

	JsonParser parser(msfrequest->toString());
	reqJsonObj = parser.getJsonObject();
	string str = reqJsonObj["salary"];
	int salary = stoi(str);
	string str1 = reqJsonObj["emp_ID"];
	int empId = stoi(str1);

	stringstream ss;
	ss << "INSERT INTO Employee_Details(emp_ID,emp_name,dateOfJoining,designation,salary) VALUE('" ;
	ss << empId<<"','";
	ss << reqJsonObj["emp_name"] <<"','";
	ss << reqJsonObj["dateOfJoining"]<<"','";
	ss << reqJsonObj["designation"] <<"',";
	ss << salary << ")";

	string sQuery = ss.str();

        string sError;

    	mysqlConnection->query(sQuery, mResult, nID, sError);

        if(sError.length()>0) {
		msfresponse->setInfoID(config2["onInvalidSet"]["id"]);
                msfresponse->setInfoMsg(config2["onInvalidSet"]["msg"]);
		msfresponse->setSvcName(config2["onInvalidSet"]["svcName"]);
		msfresponse->setSvcGroup(config2["onInvalidSet"]["svcGroup"]);
            cout << "Error in executing Query1 = " << sError << endl;
        } else {
		msfresponse->setInfoID(config2["onValidSet"]["id"]);
		msfresponse->setInfoMsg(config2["onValidSet"]["msg"]);
		msfresponse->setSvcName(config2["onValidSet"]["svcName"]);
                msfresponse->setSvcGroup(config2["onValidSet"]["svcGroup"]);

            cout << "Query executed successfully\n";
        }
	this->sendResponse(msfresponse,connection);
	connection->release();

}
