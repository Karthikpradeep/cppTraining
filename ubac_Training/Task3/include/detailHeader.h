#ifndef DETAILHEADER_H
#define DETAILHEADER_H

#include <iostream>
#include <string>
#include <sstream>
#include <jsonLanguageParser/langParser.h>
#include <sbu2webapp/SBU2WebService.h>
#include <sbu2webapp/SBU2HTTPServer.h>
#include <ubacyaml/YamlConfig.h>
#include <ubacmysql/MySql.h>

using namespace std;
using namespace SBU2;
using namespace UBACSQL;

class GetDetails : public SBU2WebService{
        public :
                GetDetails(const string& filePath);
                ~GetDetails();
                void onInvalidJSONRequest( HTTPServerRequest * request,HTTPConnection * connection,string & rawRequest);
                void onPostProcessRequest( MSFRequest * msfrequest,MSFResponse * msfresponse, HTTPConnection *connection );
        private:
		string getEmployeeDetails(int empId,MYSQL_RES *mResult);
                LangParse *langPar;
                string filePath;
                UBACSql *mysqlConnection;


};
#endif

