#ifndef LANPARSER_H
#define LANPARSER_H

#include <iostream>
#include <limits>
#include <fstream>
#include <string>
#include <sstream>
#include <jsonparser/JsonParser.h>

using namespace std;

class LangParse{
	public:
		LangParse(const string& fileName);
		~LangParse();
		void readFile();
		void displayLanguageData(string LanguageName);
		void displayAllLanguageData();
		void displayLanguageURL(string LanguageName, string id);
		void displayAllLanguageURL(string LanguageName);
		JsonObject getJsonObjects();
		JsonObject getJsonListObjects();
		JsonObject getJsonUrlObjects();
	private:
		string fileName;
		JsonObject jsonObject;
};
#endif

