#include<iostream>

using namespace std;

class Person{
public:
	string name;
	int age;
	string gender;

	void displayDetails(){
		cout<<"Name - "<<name<<endl;
		cout<<"Age - "<<age<<endl;
		cout<<"Gender - "<<gender<<endl;
	}
};

int main(){
	Person p1;
	p1.name="Harry";
	p1.age=20;
	p1.gender="Male";
	p1.displayDetails();
}
