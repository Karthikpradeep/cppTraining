#include <iostream>

using namespace std;

void print(int n){
	int i=1;//local variable
	while(i!=6){
		cout<<i<<" ";
		i++;
	}
	cout<<endl;
}

int main(){
	int n =5;
	//cout<<i<<endl;
	print(n);
	return 0;
}	

