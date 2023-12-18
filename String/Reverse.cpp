#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
	string str;

	cout<<"Enter the string - ";
	getline(cin, str);
	string str1 = str;
	reverse(str.begin(),str.end());

	cout<<"Reverse of the string "<<str1<<" is "<<str<<endl;

	return 0;
}
