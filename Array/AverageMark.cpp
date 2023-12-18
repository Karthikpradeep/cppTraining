#include <iostream>

using namespace std;

int main(){
	int n,mark1,mark2,mark3,i=1;
	cout<<"Enter the total number of students in the class - ";
	cin>>n;
	while(i!=n+1){
		cout<<"\nEnter the details of student"<<i<<endl;
		cout<<"Mark 1 - ";
		cin>>mark1;
		cout<<"Mark 2 - ";
		cin>>mark2;
		cout<<"Mark 3 - ";
		cin>>mark3;
		
		int averageMark = (mark1+mark2+mark3)/3;
		cout<<"Average mark of Student "<<i<<" is "<<averageMark<<endl;
		i++;
	}
	return 0;
}	
