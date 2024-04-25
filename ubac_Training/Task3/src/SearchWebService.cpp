#include "searchHeader.h"

SearchEmployee::SearchEmployee(const string& filePath):SBU2WebService(){
        this->filePath = filePath;
}

SearchEmployee::~SearchEmployee(){
        delete mysqlConnection;
}

void SearchEmployee::onInvalidJSONRequest( HTTPServerRequest * request,HTTPConnection * connection,string & rawRequest){
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

void SearchEmployee::onPostProcessRequest( MSFRequest * msfrequest,MSFResponse * msfresponse, HTTPConnection *connection ){
        JsonObject reqJsonObj;
        JsonObject respJsonObj;

	YamlConfig config2(filePath);
        mysqlConnection = new UBACSql(config2["DatabaseDetails"]["ip"],config2["DatabaseDetails"]["user"],config2["DatabaseDetails"]["password"],config2["DatabaseDetails"]["Database"]);
        MYSQL_RES *mResult;
	string sError;
        uint64_t nID;

        cout<<"In myWebService on post request "<<endl;
        cout<<"Request received - "<<msfrequest->toString()<<endl;
	

        JsonParser parser(msfrequest->toString());
        reqJsonObj = parser.getJsonObject();
        string str = reqJsonObj["emp_ID"];
	string sQuery = "SELECT emp_name FROM Employee_Details WHERE emp_ID = "+str;
	mysqlConnection->query(sQuery, mResult, nID, sError);
	int Rows = mysql_num_rows(mResult);

	if(Rows>0){
		msfresponse->setInfoID(config2["onValidSearch"]["id"]);
		msfresponse->setInfoMsg(config2["onValidSearch"]["msg"]);
		msfresponse->setSvcName(config2["onValidSearch"]["svcName"]);
		msfresponse->setSvcGroup(config2["onValidSearch"]["svcGroup"]);
		cout<<"Employee with id - "<<str<<" Present in Database"<<endl;
	}
	else{
		msfresponse->setInfoID(config2["onInvalidSearch"]["id"]);
                msfresponse->setInfoMsg(config2["onInvalidSearch"]["msg"]);
                msfresponse->setSvcName(config2["onInvalidSearch"]["svcName"]);
                msfresponse->setSvcGroup(config2["onInvalidSearch"]["svcGroup"]);
		cout<<"Employee with id - "<<str<<" not present in the database"<<endl;
        }

	
        sendResponse(msfresponse,connection);
        connection->release();

}

