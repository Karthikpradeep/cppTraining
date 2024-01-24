#include<iostream>
#include<unordered_map>

using namespace std;

int main(){
	int entries,value;
	string key,searchKey;
	unordered_multimap<string,int> students;

	cout<<"Enter the number of entries to be needed - ";
	cin>>entries;
	cin.ignore();
	cout<<"Enter the details of the students "<<endl;
	for(int i=0;i<entries;i++){
		cout<<"Enter the student name - ";
		getline(cin,key);
		cout<<"Enter the student mark - ";
		cin>>value;
		cin.ignore();
		//students.insert({key,value});
		students.insert(pair<string,int> (key,value));
	}

	for(auto& stud : students){
		cout<<"Name - "<<stud.first<<" Mark - "<<stud.second<<endl;
	}
	cout<<"Size of the map - "<<students.size()<<endl;
	cout<<"Enter the name to be deleted - ";
	getline(cin,searchKey);
	if(students.find(searchKey) == students.end()){
		cout<<"The student " << searchKey<<" is not found"<<endl;
	}
	else{
		cout<<"The student named "<< searchKey<<" is not found"<<endl;
		students.erase(searchKey);
	}
	cout<<"Map after deleting "<<searchKey<<endl;
	 for(auto& stud : students){
                cout<<"Name - "<<stud.first<<" Mark - "<<stud.second<<endl;
        }


	return 0;
}

