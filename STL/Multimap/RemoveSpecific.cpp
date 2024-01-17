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
	cout<<"Values of the map are"<<endl;
        for(auto i : student){
                cout<<"{"<<i.first<<","<<i.second<<"}"<<endl;
        }
	cout<<"Enter the key and value to be removed "<<endl;
	cout<<"Enter key - ";
	getline(cin,name);
	cout<<"Enter value - ";
	cin>>mark;
	
	auto range = student.equal_range(name);
	multimap<string,int> :: iterator iter;
	for(iter = range.first; iter != range.second;++iter){
		if(iter->second == mark){
			student.erase(iter);
			break;
		}
	}
	cout<<"Values in map after removing"<<endl;
	  for(auto i : student){
                cout<<"{"<<i.first<<","<<i.second<<"}"<<endl;
        }
	cout<<endl;
        return 0;
}

