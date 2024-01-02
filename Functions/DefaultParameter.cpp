#include<iostream>
#include<cmath>

using namespace std;

void power(int base, int exp){
	cout<<"square of the number "<<base<<" is "<<pow(base,exp)<<endl;
	cout<<"cube of the number "<<base<<" is "<<pow(base,++exp)<<endl;
}
int main(){
	int base,exponent = 2;
	cout<<"Enter a number to find square and cube - ";
	cin>>base;

	power(base, exponent);

	return 0;
}
