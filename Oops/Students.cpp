#include <iostream>

using namespace std;

class Student{
	private:
		static int totalStudents;

	public:
		//constructor 
		Student(){
			totalStudents++;
		}

		//destructor
		~Student(){
			//cout<<"Destructor called for object - "<<totalStudents<<endl;
			totalStudents--;
		}

		static void displayDetails(){
			cout<<"Total number of students - "<<totalStudents<<endl;
		}
};

int Student::totalStudents = 0;

int main(){
	Student s1;
	Student s2;
	Student s3;

	Student::displayDetails();//three constructors are called
	{
		Student s4; 
		Student::displayDetails();
	}
	Student::displayDetails();

}
