#include <iostream>
#include <string>

using namespace std;
int n;
struct Employee{
	int empId;
	char name[20];
	int age;
	float salary;
};
union EmployeeInfo{
	Employee personalInfo;
	Employee professionalInfo;
};

void inputEmployeeData(EmployeeInfo empInfo[],int n){
	for(int i=0;i<n;i++){
		cout<<"\nEnter Personal Information"<<endl;
		cout<<"Enter Employee Name - ";
		cin>>empInfo[i].personalInfo.name;
		cout<<"Enter Employee Age - ";
		cin>>empInfo[i].personalInfo.age;

		cout<<"\nEnter Professional Information"<<endl;
		cout<<"Enter Employee ID - ";
                cin>>empInfo[i].professionalInfo.empId;
                cout<<"Enter salary - ";
                cin>>empInfo[i].professionalInfo.salary;

	}

}
void displayEmployeeData(EmployeeInfo empInfo[],int n){
	for(int i=0;i<n;i++){
		cout<<"\nPersonal Information"<<endl;
		cout<<"Employee Name - "<<empInfo[i].personalInfo.name<<endl;
		cout<<"Employee Age - "<<empInfo[i].personalInfo.age<<endl;

		cout<<"Professional Information"<<endl;
		cout<<"Employee ID - "<<empInfo[i].professionalInfo.empId<<endl;
                cout<<"Employee Salary - "<<empInfo[i].professionalInfo.salary<<endl;
	}
}

int main(){
	int n;
	cout<<"Enter the number of employees - ";
	cin>>n;
	EmployeeInfo empInfo[n];
	inputEmployeeData(empInfo, n);
	displayEmployeeData(empInfo, n);
	return 0;
}
