#ifndef SEARCHHEADER_H
#define SEARCHHEADER_H

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

class SearchEmployee : public SBU2WebService{
        public :
                SearchEmployee(const string& filePath);
                ~SearchEmployee();
                void onInvalidJSONRequest( HTTPServerRequest * request,HTTPConnection * connection,string & rawRequest);
                void onPostProcessRequest( MSFRequest * msfrequest,MSFResponse * msfresponse, HTTPConnection *connection );
        private:
                LangParse *langPar;
                string filePath;
                UBACSql *mysqlConnection;


};
#endif
