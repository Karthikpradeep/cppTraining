#include <iostream>
#include <string>

using namespace std;

int main(){
	string str;

	cout<<"Enter the string - ";
	getline(cin, str);
	
	string str1;

	cout<<"Enter the string or character to be checked - ";
	getline(cin, str1);

	if(str.find(str1) != string::npos){
		cout<<"The second string "<<str1<<" is present in the first string"<<endl;
	}
	else{
		cout<<"The second steing "<<str1<<" is not present in the first "<<endl;
	}

	return 0;
}

