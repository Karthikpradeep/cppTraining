#include <iostream>

using namespace std;

int main(){
	int i=1,n,num1=0,num2=1,next;

	cout<<"Enter the number of terms needed - ";
	cin>>n;

	while(i<=n)
	{
		next=num1+num2;
		cout<<next<<" ";
		num1=num2;
		num2=next;
		i++;
	}
	cout<<endl;
	return 0;
}


