#include <iostream>

using namespace std;

int main(){
	string str;
	cout<<"Enter the string - ";
	getline(cin, str);

	const char *str2 = str.c_str();

	cout<<"The given string is - "<<str2<<endl;

	return 0;
}


