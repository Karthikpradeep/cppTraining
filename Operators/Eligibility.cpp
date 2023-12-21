
#include <iostream>

using namespace std;

int main(){
	int sub1,sub2,sub3,sub4;
	
	cout<<"Enter the mark of sub1 - ";
	cin>>sub1;
	cout<<"Enter the mark of sub2 - ";
	cin>>sub2;
	cout<<"Enter the mark of sub3 - ";
	cin>>sub3;
	cout<<"Enter the mark of sub4 - ";
	cin>>sub4;
	
	if(sub1>90 && sub2>90 && sub3>90 && sub4>90){
		cout<<"Eligible for Group A"<<endl;
	}
	else if(sub1>80 && sub2>80 && sub3>70 && sub4>70){
		cout<<"Eligible for Group B"<<endl;
	}
	else if(sub3>80 || sub4>80){
		cout<<"Eligible for Group C"<<endl;
	}
	else if(sub3>70 && sub4>70 || sub1>75){
		cout<<"Eligible for Group D"<<endl;
	}

	return 0;
}

