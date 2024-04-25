#ifndef USERLOGIN_H
#define USERLOGIN_H

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

class userLogin : public SBU2WebService{
        public:
                userLogin(string);
                ~userLogin();
                void onInvalidJSONRequest( HTTPServerRequest * request,HTTPConnection * connection,string & rawRequest);
                void onPostProcessRequest( MSFRequest * msfrequest,MSFResponse * msfresponse, HTTPConnection *connection );
        private:
                string filePath;
		string group="Registration",name="Login",version="1.0.0";
};
#endif
