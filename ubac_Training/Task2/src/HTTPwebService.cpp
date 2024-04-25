#include "webHeader.h"

HTTPwebService::HTTPwebService(const string& fileName,const string& filepath) : SBU2WebService() {
	langPar = new LangParse(fileName);
	langPar->readFile();
	this->filePath = filepath;
}

HTTPwebService::~HTTPwebService(){
	delete langPar;
	cout<<" Closing the server "<<endl;
}

void HTTPwebService::onInvalidJSONRequest( HTTPServerRequest * request,HTTPConnection * connection,string & rawRequest){
	cout<<"Request recieved - "<<rawRequest<<endl;
	string id,msg;
	YamlConfig config1(filePath);
	cout<<filePath<<endl;
	id = config1["onInvalidJson"]["id"];
	msg = config1["onInvalidJson"]["msg"];

	MSFRequest *msfReq = new MSFRequest(rawRequest);

	MSFResponse *errResp = new MSFResponse(msfReq);
	errResp->setInfoID(id);
	errResp->setInfoMsg(msg);
	errResp->setSvcName(config1["onInvalidJson"]["svcName"]);
        errResp->setSvcGroup(config1["onInvalidJson"]["svcGroup"]);
	sendResponse(errResp,connection);
        connection->release();
}

void HTTPwebService::onPostProcessRequest( MSFRequest * msfrequest,MSFResponse * msfresponse, HTTPConnection *connection ){
	JsonObject reqJsonObj;
	JsonObject respJsonObj;
	cout << "In MyWebSerivce on post request: sRequest = " << endl;
	cout << "Request received ... " << msfrequest->toString() << endl;
	cout<<filePath<<endl;
	YamlConfig config2(this->filePath);
	
	JsonParser parser(msfrequest->toString());
	reqJsonObj = parser.getJsonObject();
	string val;
	if(reqJsonObj.hasKey(config2["onPostProcessRequest"]["key"])){
		val = reqJsonObj[config2["onPostProcessRequest"]["key"]];
		if(val == config2["onPostProcessRequest"]["value1"]){
			respJsonObj = langPar->getJsonListObjects();

		}
		else if(val == config2["onPostProcessRequest"]["value2"]){
			respJsonObj = langPar->getJsonUrlObjects();
		}
		else{
			string id = config2["onPostProcessRequest"]["id"];
		        string msg = config2["onPostProcessRequest"]["msg"];

			msfresponse->setInfoID(id);
        		msfresponse->setInfoMsg(msg);	
		}
	}

	//msfresponse->setSvcVersion("1.0.1");
	msfresponse->setSvcName(config2["onPostProcessRequest"]["svcName"]);
	msfresponse->setSvcGroup(config2["onPostProcessRequest"]["svcGroup"]);
	msfresponse->addToData(config2["onPostProcessRequest"]["key"], respJsonObj);

	cout<<respJsonObj.toString()<<endl;
	this->sendResponse(msfresponse,connection);
	
	connection->release();
}	

