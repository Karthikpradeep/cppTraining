#ifndef ADMINPORTAL_H
#define ADMINPORTAL_H

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

class adminPortal : public SBU2WebService{
        public:
                adminPortal(string);
                ~adminPortal();
 
                void onInvalidJSONRequest( HTTPServerRequest * request,HTTPConnection * connection,string & rawRequest);
                void onPostProcessRequest( MSFRequest * msfrequest,MSFResponse * msfresponse, HTTPConnection *connection );
        private:
                string filePath;
};
#endif
