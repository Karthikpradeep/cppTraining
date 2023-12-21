#include <iostream>

using namespace std;

void print(int n){
	int i;//local variable
	for(i=1;i<=n;i++){
		cout<<i<<" ";
	}
	cout<<endl;
}

int main(){
	int n =5;
	//cout<<i<<endl;
	print(n);
	return 0;
}	

