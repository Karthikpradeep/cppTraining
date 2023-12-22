#include <iostream>

using namespace std;

int value(){
	return 5;
}
int main(){
	int a=100,b=50;

	cout<<a-b/value()<<endl;/*Precedence function call -> division -> sub */

	return 0;
}
