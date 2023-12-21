#include <iostream>

using namespace std;

int main(){
	int month;
	bool check = true;
	while(check){
		cout<<"Enter the month - ";
		cin>>month;

		if(month<1 || month>12){
			cout<<"!!! Invalid month !!!"<<endl;
		}
		else{
			check = false;
		}
	}
	if(month>=3 && month<=5){
		cout<<"Summer"<<endl;
	}
	else if(month>=6 && month<=8){
		cout<<"Spring"<<endl;
	}
	else if(month>=9 && month<=11){
		cout<<"Rainy"<<endl;
	}
	else{
		cout<<"Autumn"<<endl;
	}

	return 0;
}
