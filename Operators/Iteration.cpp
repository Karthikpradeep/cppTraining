/*Get n which should be greater than 10 from user (if not, give error message and make user to provide n again). 
 Loop n times and print "You are in iteration number - 1", "You are in iteration number - 2" till n but not for iteration number 5.*/
#include <iostream>

using namespace std;

int main(){
	int n,i=1;
	bool isValidInput = true;

	while(isValidInput){
		cout<<"Enter the value of n -";
		cin>>n;

		if(n<=10){
			cout<<"!!! Invalid input !!!"<<endl;
			cout<<"Number should be greater than 10"<<endl;
		}
		else{
			isValidInput = false;
		}
	}
	while( i<=n){
		if(i==5){
			i++;
			continue;
		}
		cout<<"You are in iteration number - "<<i<<endl;
		i++;
	}
	/*while(i<=n){
		if(i!=5){
			cout<<"You are in iteration number - "<<i<<endl;
		}
		i++;
	}*/

	return 0;
}

