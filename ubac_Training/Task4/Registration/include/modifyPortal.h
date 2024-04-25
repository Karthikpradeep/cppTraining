#ifndef MODIFYPORTAL_H
#define MODIFYPORTAL_H

#include <iostream>
#include <string>
#include <sstream>
#include <jsonLanguageParser/langParser.h>
#include <sbu2webapp/SBU2WebService.h>
#include <sbu2webapp/SBU2HTTPServer.h>
#include <ubacyaml/YamlConfig.h>
#include <ubacmysql/MySql.h>

#include "sqlConn.h"

using namespace std;
using namespace SBU2;
using namespace UBACSQL;

class modifyPortal : public SBU2WebService{
        public:
                modifyPortal(string);
                ~modifyPortal();
		string determineGrade(int);
                void onInvalidJSONRequest( HTTPServerRequest * request,HTTPConnection * connection,string & rawRequest);
                void onPostProcessRequest( MSFRequest * msfrequest,MSFResponse * msfresponse, HTTPConnection *connection );
        private:
                string filePath;
};
#endif

