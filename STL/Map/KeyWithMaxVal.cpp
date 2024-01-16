#include<iostream>
#include<map>

using namespace std;

void MaxVal(map<string,int> employee){
	
	map<string,int> ::iterator iter;
	map<string,int> ::iterator iter2;
	map<string,int> ::iterator iter3;
	iter3 = employee.end();
	--iter3;
	iter2=employee.begin();
	int large = iter2->second;
	string emp;
	++iter2;
	for(iter = employee.begin();iter != iter3;++iter){
		if(iter->second<iter2->second){
			large = iter2->second;
			emp = iter2->first;
		}
		++iter2;
	}
	cout<<"Employee - "<<emp<<" has the highest salary of rs"<<large<<endl;
}
int main(){
	map<string, int> employee;
	int num,value;
	string key;
	cout<<"Enter the number of employees - ";
	cin>>num;
	cin.ignore();
	cout<<"Enter the employee name and salary "<<endl;
	for(int i=0;i<num;i++){
		cout<<"Enter name - ";
	      	getline(cin, key);
		
		cout<<"Enter salary - ";
		cin>>value;
		employee[key] = value;
		cin.ignore();
	}
	MaxVal(employee);

	return 0;
}	
