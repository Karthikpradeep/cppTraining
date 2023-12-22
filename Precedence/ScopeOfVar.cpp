#include <iostream>

using namespace std;
int value;
int  mul(int c,int d){
	value=c*d;
	return value;
}
int main(){
	int a,b;
	cout<<"Multiplication"<<endl;
	cout<<"Enter value of a - ";
	cin>>a;
	cout<<"Enter value of b - ";
	cin>>b;
	value = mul(a,b);
	cout<<"Product of "<<a<<" and "<<b<<" is  "<<value<<endl; 
	return 0;
}
