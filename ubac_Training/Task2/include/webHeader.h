#ifndef WEBHEADER_H
#define WEBHEADER_H

#include <iostream>
#include <string>
#include <jsonLanguageParser/langParser.h>
#include <sbu2webapp/SBU2WebService.h>
#include <sbu2webapp/SBU2HTTPServer.h>
#include <ubacyaml/YamlConfig.h>

using namespace std;
using namespace SBU2;

class HTTPwebService : public SBU2WebService{
	public :
		HTTPwebService(const string& fileName,const string& filepath);
		~HTTPwebService();
		void onInvalidJSONRequest( HTTPServerRequest * request,HTTPConnection * connection,string & rawRequest);
		void onPostProcessRequest( MSFRequest * msfrequest,MSFResponse * msfresponse, HTTPConnection *connection );
		
	private :
		LangParse *langPar;
		string fileName,filePath;
};
#endif

