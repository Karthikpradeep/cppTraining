#include <iostream>

using namespace std;

void swapNumbers(int &num1,int &num2){

	int temp=num1;
	num1 = num2;
	num2 = temp;
}
int main(){
	int num1,num2;
	cout<<"Enter the number 1 - ";
	cin>>num1;

	cout<<"Enter the number 2 - ";
	cin>>num2;

	cout<<"\nNumbers before swapping"<<endl;
	cout<<"Number 1 - "<<num1<<endl;
	cout<<"Number 2 - "<<num2<<endl;

	swapNumbers(num1,num2);
	cout<<"\nNumbers after swapping"<<endl;
	cout<<"Number 1 - "<<num1<<endl;
	cout<<"Number 2 - "<<num2<<endl;
	return 0;
}
