#include <iostream>

using namespace std;

string stringCopy(string str1,string str2){
    char* src = &str1[0];
    char* dest = &str2[0];
    while(*src != '\0'){
        *dest = *src;
        *dest++;
        *src++;
    }	
    return str2;
    
}
int main(){
	string str1;
	cout<<"Enter the string - ";
	getline(cin, str1);

	string str2 = "";
	int length = str1.length();
	char fill = ' ';
	str2.resize(length, fill);
	cout<<"copied string is - "<<stringCopy(str1,str2)<<endl;
	return 0;
}
