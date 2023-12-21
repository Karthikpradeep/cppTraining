
#include <iostream>

using namespace std;

int main(){
	string name;
	int age, mark;
	cout<<"Enter student name - ";
	getline(cin, name);

	cout<<"Enter student age - ";
	cin>>age;
	bool check = true;

	cout<<"Enter student mark out of 100 - ";
	cin>>mark;

	if(age>=18 && mark>80){
		cout<<"Eligible for Merit admission"<<endl;
	}
	else if(age>=18 && mark>60){
		cout<<"Eligible for non-merit admission"<<endl;
	}
	else if(age>=18 && mark<=60){
		cout<<"Cut-off mark is low for the admission"<<endl;
	}
	else if(age<18){
		cout<<"Under age for admission"<<endl;
	}

	return 0;
}
