#include<iostream>
#include<map>

using namespace std;

void Values(multimap<string,int> student, string name){
	auto range = student.equal_range(name);
	multimap<string, int> :: iterator iter;
	for(iter = range.first;iter!=range.second;++iter){
		cout<<iter->second<<" ";
	}
	cout<<endl;
}
int main(){
        multimap<string, int> student;
        int size,mark;
        string name;
        cout<<"Enter the number of entries - ";
        cin>>size;
        cin.ignore();
        cout<<"Enter the name and mark out of 100 "<<endl;
        for(int i=0;i<size;i++){
                cout<<"Enter the student name - ";
                getline(cin,name);
                cout<<"Enter the student mark - ";
                cin>>mark;
                cin.ignore();
                student.insert(pair<string,int>(name,mark));
        }
	cout<<"\nEnter the key to be searched - ";
       	getline(cin,name);
	Values(student,name);	
        return 0;
}

