#include <iostream>

using namespace std;

int stringLength(string str){
	int count = 0;
	char* ptr = &str[0];
	while(*ptr != '\0'){
		count++;
		*ptr++;
	}
	return count;
}

int main(){
	//string myString = "String length finder";
	string myString;
	cout<<"Enter the string to find the length - ";
	getline(cin, myString);
	int length = stringLength(myString);
	cout<<"The length of the string --"<<myString<<"-- is - "<<length<<endl;
	return 0;
}
