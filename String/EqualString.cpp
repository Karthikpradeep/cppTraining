#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	string str1,str2;

	cout<<"Enter the first string - ";
	getline(cin, str1);

	cout<<"Enter the second string - ";
	getline(cin, str2);

	if(str1 == str2){
		cout<<"The given string "<<str1<<" and string "<<str2<<" are equal"<<endl;
	}
	else{
		cout<<"The given string "<<str1<<" and string "<<str2<<" are not equal"<<endl;
	}
	sort(str1.begin(),str1.end());
	sort(str2.begin(),str2.end());
	if (str1 == str2){
		cout<<"The given two strings have same characters"<<endl;
	}
	else{
		cout<<"The given two strings have doesn't have same characters"<<endl;
	}
	return 0;
}

