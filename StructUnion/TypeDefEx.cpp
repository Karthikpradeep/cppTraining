#include<iostream>

using namespace std;

typedef struct Student{
	string name;
	int age;
	int stdId;
}students;

int main(){
	int n,i;
	cout<<"Enter the number of students - ";
	cin>>n;
	students std[n];
	//typedef struct Student students;
	for(i=0;i<n;i++){
		cout<<"\nEnter student name - ";
		cin>>std[i].name;
		cout<<"Enter student age - ";
		cin>>std[i].age;
		cout<<"Enter student id - ";
		cin>>std[i].stdId;
	}	
	
	return 0;
}
