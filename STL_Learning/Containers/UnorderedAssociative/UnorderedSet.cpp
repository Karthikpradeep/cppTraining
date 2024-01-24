// Here the insertion is always randomized but the elements will be unique
#include<iostream>
#include<unordered_set>

using namespace std;

int main(){
	int entries;
	string name,key;
	unordered_set<string> names;
	
	cout<<"Enter the number of entries needed - ";
	cin>>entries;
	cin.ignore();
	cout<<"Enter the names - ";
	for(int i=0;i<entries;i++){
		getline(cin,name);
		names.insert(name);
	}

	cout<<"Entered names are - ";
	for(string i : names){
		cout<<i<<" ";
	}
	cout<<endl;

	cout<<"size of the unordered set is - "<<names.size()<<endl;
	cout<<"Enter the element to be deleted - ";
	getline(cin,key);
	if(names.find(key) == names.end()){
		cout<<"The name "<<key<<" is not found in the set"<<endl;
	}
	else{
		cout<<"The name "<<key<<" is found in the set"<<endl;
		names.erase(key);
		cout<<key<<" deleted from the unordered set"<<endl;
	}
	cout<<"\nSet after deletion"<<endl;
	for(string str : names){
		cout<<str<<" ";
	}
	cout<<endl;
	

	return 0;
}
