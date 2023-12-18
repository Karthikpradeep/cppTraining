#include <iostream>
#include <cctype>
using namespace std;

int main(){
	string str;
	cout<<"Enter the string - ";
	getline(cin, str);
	cout<<"String using toupper function - ";
	for(int i=0;i<str.length();i++){
		cout<< static_cast<char> (toupper(str[i]));
	}
	cout<<endl;
	cout<<"String using tolower function - ";
	for(int i=0;i<str.length();i++){
		cout<< static_cast<char> (tolower(str[i]));
	}
	cout<<endl;

	return 0;
}
