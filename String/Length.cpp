#include <iostream>

using namespace std;

int main(){
	string str;
	cout<<"Enter the string - ";
	getline(cin, str);

	int length = str.length();
	cout<<"The length of the given string "<<str<<" is "<<length<<endl;
	return 0;
}

