#ifndef SETHEADER_H
#define SETHEADER_H

#include <iostream>
#include <string>
#include <jsonLanguageParser/langParser.h>
#include <sbu2webapp/SBU2WebService.h>
#include <sbu2webapp/SBU2HTTPServer.h>
#include <ubacyaml/YamlConfig.h>
#include <ubacmysql/MySql.h>

using namespace std;
using namespace SBU2;
using namespace UBACSQL;

class SetDetails : public SBU2WebService{
	public :
		SetDetails(const string& filePath);
		~SetDetails();
		void onInvalidJSONRequest( HTTPServerRequest * request,HTTPConnection * connection,string & rawRequest);
                void onPostProcessRequest( MSFRequest * msfrequest,MSFResponse * msfresponse, HTTPConnection *connection );
	private:
		LangParse *langPar;
		string filePath;
		UBACSql *mysqlConnection;
		

};
#endif
