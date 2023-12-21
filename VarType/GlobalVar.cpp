#include <iostream>

using namespace std;

int i=20;

void print(){

	cout<<++i<<endl;
}

int main(){
	print();
	cout<<i++<<endl;
	return 0;
}
