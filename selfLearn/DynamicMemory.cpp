#include<iostream>

using namespace std;

class Employee{
	private:
		string name;
		int empId;

	public:
		void setName(string Name){
			name = Name;
		}

		void setId(int EmpId){
			empId = EmpId;
		}

		string getName(){
			return name;
		}

		int getId(){
			return empId;
		}
};
int main(){
	Employee emp1;
	Employee *ptr = &emp1;
	ptr = new Employee;

	ptr->setName("Ram"); //(*ptr). == ptr->
	(*ptr).setId(101);

	cout<<"Name - "<<ptr->getName()<<endl;
	cout<<"Id - "<<(*ptr).getId()<<endl;
	delete ptr;
}

