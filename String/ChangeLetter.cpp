#include <iostream>

using namespace std;

int main(){
	string str;

	cout<<"Enter the string - ";
	getline(cin, str);
	
	for(int i=0;i<str.length();i++){
		char &c = str[i];
		if(isalpha(c)){
			if(c == 'z' || c == 'Z'){
				c = (c == 'z') ? 'a' : 'A';
			}
			else{
				c++;
			}
		}
	}
	cout<<"Modified string - "<<str<<endl;

	return 0;
}
