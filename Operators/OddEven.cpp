#include <iostream>

using namespace std;

int main(){
	int num;

	cout<<"Enter the number to check odd or even - ";
	cin>>num;

	if(num%2 == 0){
		cout<<"The given number "<<num<<" is even"<<endl;
	}
	else{
		cout<<"The given number "<<num<<" is odd"<<endl;
	}

	cout<<"Checking using ternary operator "<<endl;

	(num%2 == 0) ? cout<<num<<" is even" : cout<<num<<" is odd"<<endl;

	return 0;
}

