#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
	string str;

	cout<<"Enter the string - ";
	getline(cin, str);

	string str1 = str;

	reverse(str.begin(),str.end());

	if(str1 == str){
		cout<<"The given string "<<str1<<" is palindrome"<<endl;
	}
	else{
		cout<<"The given string "<<str1<<" is not palindrome"<<endl;
	}

	return 0;
}

