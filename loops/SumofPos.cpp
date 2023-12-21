#include <iostream>

using namespace std;

int main(){
	int num,sum = 0,i=1;
	cout<<"Enter any number  -";
	cin>>num;
	while(i<=num){
		int n;
		cout<<"Enter number "<<i<<"- ";
		cin>>n;
		if(n>0){
			sum+=n;
			cout<<"sum of numbers till now "<<sum<<endl;
		}
		else{
			cout<<"The entered number "<<n<<" is a negative number. Please enter a poitive number "<<endl;
			num++;
		}
		i++;
	}
	

        return 0;
}

