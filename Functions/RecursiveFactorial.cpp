#include <iostream>

using namespace std;
int fact =1;
void factorial(int num){
		
	if(num>1){
		fact=fact*num;
		num--;
		factorial(num);
	}
	else{
		cout<<"Factorial of number is - "<<fact<<endl;

	}
}

int main(){
	int num;
	cout<<"Enter the number to find the factorial - ";
	cin>>num;

	factorial(num);
	return 0;
}
