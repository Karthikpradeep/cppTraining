#include<iostream>
#include<unordered_map>


using namespace std;

int main(){
	int entries,key,searchKey;
	string value;

	unordered_map<int,string> employee;

	cout<<"Enter the number of entries needed - ";
	cin>>entries;

	for(int i=0;i<entries;i++){
		cout<<"Enter the employee id - ";
		cin>>key;
		cin.ignore();
		cout<<"Enter the name of the employee - ";
		getline(cin,value);
		employee[key] = value;
	}

	cout<<"\nEmployee details"<<endl;
	for(auto emp : employee){
		cout<<emp.first<<" "<< emp.second<<endl;
	}

	cout<<"Enter the employee id to be searched - ";
	cin>>searchKey;

	if(employee.find(searchKey) == employee.end()){
		cout<<"Employee id "<<searchKey<<" not found"<<endl;
	}
	else{
		cout<<"Employee found"<<endl;
		cout<<searchKey<<" "<<employee.at(searchKey)<<endl;
	}
	return 0;
}

