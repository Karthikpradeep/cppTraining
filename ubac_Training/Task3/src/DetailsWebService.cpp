#include "detailHeader.h"

GetDetails::GetDetails(const string& filePath):SBU2WebService(){
        this->filePath = filePath;
}

GetDetails::~GetDetails(){
        delete mysqlConnection;
}

void GetDetails::onInvalidJSONRequest( HTTPServerRequest * request,HTTPConnection * connection,string & rawRequest){
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

void GetDetails::onPostProcessRequest( MSFRequest * msfrequest,MSFResponse * msfresponse, HTTPConnection *connection ){
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
        int empId = stoi(str);
        string sQuery = "SELECT * FROM Employee_Details WHERE emp_ID = "+str;

        mysqlConnection->query(sQuery, mResult, nID, sError);
        int Rows = mysql_num_rows(mResult);

        if(Rows>0){
		msfresponse->setInfoID(config2["onValidDetails"]["id"]);
                msfresponse->setInfoMsg(config2["onValidDetails"]["msg"]);
		msfresponse->setSvcName(config2["onValidDetails"]["svcName"]);
		msfresponse->setSvcGroup(config2["onValidDetails"]["svcGroup"]);
	
		string employeeDetails = getEmployeeDetails(empId,mResult);
		cout<<employeeDetails<<endl;
		JsonParser par(employeeDetails);
		respJsonObj = par.getJsonObject();
		msfresponse->addToData("Employee_details",respJsonObj);
	
	}	
        else{
                msfresponse->setInfoID(config2["onInvalidDetails"]["id"]);
                msfresponse->setInfoMsg(config2["onInvalidDetails"]["msg"]);
                msfresponse->setSvcName(config2["onInvalidDetails"]["svcName"]);
                msfresponse->setSvcGroup(config2["onInvalidDetails"]["svcGroup"]);
        }
        sendResponse(msfresponse,connection);
        connection->release();

}
string GetDetails::getEmployeeDetails(int empId,MYSQL_RES *mResult){
	MYSQL_ROW row;
	string empDetails;
        while ((row = mysql_fetch_row(mResult))) {

            int emp_ID = atoi(row[0]);
	    string emp_Name = row[1];
            string dateOfJoining = row[2];
            string designation = row[3];
            int salary = atoi(row[4]);

            stringstream ss;
	    ss << "{";
    	    ss << "\"Employee Name\": \"" << emp_Name << "\", \"Employee ID\": " << emp_ID << ", \"Date of Joining\": \"" << dateOfJoining << "\", \"Designation\": \"" << designation << "\", \"Salary\": " << salary;
    	    ss << "}";
           empDetails = ss.str();

	}
	return empDetails;
}
