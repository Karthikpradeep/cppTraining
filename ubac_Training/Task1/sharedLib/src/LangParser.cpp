#include <jsonLanguageParser/langParser.h>

LangParse::LangParse(const string& fileName) : fileName(fileName) {
}

LangParse::~LangParse() {
}

JsonObject LangParse::getJsonObjects(){
	return jsonObject;
}

JsonObject LangParse::getJsonListObjects(){
	if(jsonObject.hasKey("LangList")){
		return jsonObject["LangList"];
	}
	else{
		 cerr<<"!!! ERROR - JSON file does not contain the key langlist !!!"<<endl;
		 return JsonObject();
	}
}
JsonObject LangParse::getJsonUrlObjects(){
	if(jsonObject.hasKey("LangUrl")){
		return jsonObject["LangUrl"];
	}
	else{
	         cerr<<"!!! ERROR - JSON file does not contain the key langUrl !!!"<<endl;
                 return JsonObject();
        }
}

void LangParse::readFile() {
	string jsonString;
	ifstream file;
	file.open(fileName);
	if (!file) {
		cout << "!!! Error occurred while opening the file !!!" << endl;
	} else {
		ostringstream ss;
		ss << file.rdbuf();
		jsonString = ss.str();
		JsonParser parser(jsonString);
		jsonObject = parser.getJsonObject();
	}
	file.close();
}

void LangParse::displayLanguageData(string LanguageName){
	bool found = false;
	if(!jsonObject.hasKey("LangList")){
		cerr<<"!!! ERROR - JSON file does not contain LangList key !!!"<<endl;
		return;
	}
	else{
		JsonObject jsonListObj = jsonObject["LangList"];
		int length = (int)jsonListObj.size();		
		for(int i=0;i<length;++i){
			if(LanguageName == (jsonListObj[i]["lang"])){
				found = true;
				cout<<"Language Name - "<<jsonListObj[i]["lang"]<<endl;
				cout<<"Localized Language Name - "<<jsonListObj[i]["dispLang"]<<endl;
				cout<<"Display text - "<<jsonListObj[i]["chgMsg"]<<endl;
				break;
			}
			
		}
		if(!found){
			cout<<"Language - "<<LanguageName<<" not found"<<endl;
		}
	}
}

void LangParse::displayAllLanguageData(){
	
	if(!jsonObject.hasKey("LangList")){
		cerr<<"!!! ERROR - JSON file does not contain LangList key !!!"<<endl;
		return;
	}
	else{
		JsonObject jsonListObject = jsonObject["LangList"];
		int length = (int)jsonListObject.size();

		for(int i=0;i<length;++i){
			string languageName = (jsonListObject[i]["lang"]);
			displayLanguageData(languageName);
		}
	}
}

void LangParse::displayLanguageURL(string LanguageName, string id){
	bool found = false;
	if(!jsonObject.hasKey("LangUrl")){
		cerr<<"!!! ERROR - JSON file does not contain LangUrl !!!"<<endl;
		return;
	}
	else{
		JsonObject jsonUrlObj = jsonObject["LangUrl"];
		JsonObject jsonIdUrlObj = jsonUrlObj[LanguageName]["value"];

		int length = (int)jsonIdUrlObj.size();

		for(int i=0;i<length;++i){
			if(id == jsonIdUrlObj[i]["id"]){
				found = true;
				cout<<"id - "<<jsonIdUrlObj[i]["id"]<<endl;
				cout<<"FT URI - "<<jsonIdUrlObj[i]["ftURI"]<<endl;
				cout<<"Omnesys URI - "<<jsonIdUrlObj[i]["omneURI"]<<endl;

				break;
			}
		}
		if(!found){
                        cout<<"Language id  - "<<id<<" for Language "<<LanguageName<<" not found"<<endl;
                }
	}
}

void LangParse::displayAllLanguageURL(string LanguageName){
	if(!jsonObject.hasKey("LangUrl")){
		cerr<<"!!! ERROR - JSON file does not contain LangUrl !!!"<<endl;
		return;
	}
	else{
		JsonObject jsonUrlObject = jsonObject["LangUrl"];
		JsonObject jsonIdUrlObject = jsonUrlObject[LanguageName]["value"];

		int length = (int)jsonIdUrlObject.size();

		for(int i=0;i<length;++i){
			string id = jsonIdUrlObject[i]["id"];
			displayLanguageURL(LanguageName,id);
		}
	}
}

