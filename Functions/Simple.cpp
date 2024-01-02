#include<iostream>

using namespace std;

int SumOfIntegers(int a,int b){
	int sum = a+b;
	return sum;
}

int main(){
	int a, b;
	cout<<"Enter the value of first integer - ";
	cin>>a;
	cout<<"Enter the value of second integer - ";
	cin>>b;
	int result = SumOfIntegers(a,b);
	cout<<"Sum of integers "<<a<<" and "<<b<<" is - "<<result<<endl;

	return 0;
}

