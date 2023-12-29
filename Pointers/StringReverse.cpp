#include <iostream>

using namespace std;

void stringReverse(string str){
	int len = str.length();
	char* start = &str[0];
	char* end = &str[len-1];

	while(start<end){
		char temp = *start;
		*start = *end;
		*end = temp;

		start++;
		end--;
	}
	cout<<str<<endl;

}

int main(){
	string str;
	cout<<"Enter the string - ";
	getline(cin, str);
	stringReverse(str);
	return 0;
}

