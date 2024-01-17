#include<iostream>
#include<map>

using namespace std;

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
	for(auto i : student){
		cout<<"{"<<i.first<<","<<i.second<<"}"<<endl;
	}

	return 0;
}
