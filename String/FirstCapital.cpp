#include <iostream>
#include <cctype>

using namespace std;

int main(){
	string str;

	cout<<"Enter the string - ";
	getline(cin, str);

	for(int i=0;i<str.length();i++){
		if(i==0 || str[i-1] == ' '){
			str[i] =toupper(str[i]);
		}
		if (str[i] == ' ' && str[i - 1] == ' ') {
         		 str.erase(i, 1);
           		 i--; 
       		 }
	}
	cout<<"Formated string - "<<str<<endl;

	return 0;
}

