#include<iostream>

using namespace std;

int main(){
	int* ptr1 = new int;
	*ptr1 = 8;
	int* ptr2 = new int;
	*ptr2 = 10;
	int sum = *ptr1+*ptr2;
	cout<<"The sum of "<<*ptr1<<" and "<<*ptr2<<" is "<<sum<<endl;
	delete ptr1;
	delete ptr2;
	return 0;
}	
