#include <jsonLanguageParser/langParser.h>

int main(){
	string path;
	int choice,arrLength;
	bool found = false;

	cout<<"Enter the file path - ";
	cin>>path;

	LangParse lan(path);
	lan.readFile();

	while(true){
		string LanguageName,id;
		cout<<"\n------Menu------"<<endl;
		cout<<"1. Select Language List "<<endl;
		cout<<"2. Select Language URL "<<endl;
		cout<<"3. Exit"<<endl;
		cout<<"Enter your choice - ";
		JsonObject jsonListObj;
		JsonObject UrlObject;
		JsonObject jsonIdUrlObj;
		if(cin>>choice){
			switch(choice){
				case 1:

					cout<<"Enter a single language name or enter ALL  "<<endl;

					jsonListObj = lan.getJsonListObjects();
					arrLength = jsonListObj.size();
					cout<<"The availabe objects are given below - "<<endl;
					for(int i=0;i<arrLength;++i){
						cout<<jsonListObj[i]["lang"]<<endl;
					}
					cout<<"Enter your choice - ";
					cin>>LanguageName;
					if(LanguageName == "ALL" || LanguageName == "all"){
						for(int i=0;i<arrLength;++i){
							cout<<"Language Name - "<<jsonListObj[i]["lang"]<<endl;
							cout<<"Localized Language Name - "<<jsonListObj[i]["dispLang"]<<endl;
							cout<<"Display text - "<<jsonListObj[i]["chgMsg"]<<endl;
						}

					}
					else{

						for(int i=0;i<arrLength;++i){
							if(LanguageName == (jsonListObj[i]["lang"])){
								found = true;
								cout<<"Language Name - "<<jsonListObj[i]["lang"]<<endl;
								cout<<"Localized Language Name - "<<jsonListObj[i]["dispLang"]<<endl;
								cout<<"Display text - "<<jsonListObj[i]["chgMsg"]<<endl;
								break;
							}

						}
						if(!found){
							cout<<"Language "<<LanguageName<<" not present "<<endl;
						}


					}
					break;
				case 2:
					
					cout<<"Enter the language name from the options below "<<endl;
					UrlObject = lan.getJsonUrlObjects();
					jsonListObj = lan.getJsonListObjects();

					arrLength = jsonListObj.size();
					for(int i=0;i<arrLength;++i){
						cout<<jsonListObj[i]["lang"]<<endl;
					}
					cout<<"Enter the language - ";
					cin>>LanguageName;
					if(UrlObject.hasKey(LanguageName)){
						jsonIdUrlObj = UrlObject[LanguageName]["value"];
						cout<<"Enter a specific id or Enter ALL - ";
						cin>>id;

						if(id == "ALL" || id == "all"){
							for(int i=0;i<jsonIdUrlObj.size();++i){
								cout<<"id - "<<jsonIdUrlObj[i]["id"]<<endl;
								cout<<"FT URI - "<<jsonIdUrlObj[i]["ftURI"]<<endl;
								cout<<"Omnesys URI - "<<jsonIdUrlObj[i]["omneURI"]<<endl;

							}
						}

						else{



							for(int i=0;i<jsonIdUrlObj.size();++i){

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
					else{
						cout<<"Language "<<LanguageName<< " not present in the json file"<<endl;
					}
					break;
				case 3:
					cout<<"Exiting the program"<<endl;
					exit(0);
					break;

				default:
					cout<<"Invalid choice try again"<<endl;
					break;
			}
		}
		else{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
			cout<<"Please enter the number in the menu "<<endl;
		}
	}
	return 0;
}
