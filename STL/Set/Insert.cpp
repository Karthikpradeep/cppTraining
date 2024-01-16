#include<iostream>
#include<set>

using namespace std;

int main(){
	set<int> mySet;
	int size,num;
	cout<<"Enter the size of the set - ";
	cin>>size;

	cout<<"Enter the elements to the set "<<endl;
	for(int i=0;i<size;i++){
		cout<<"Element "<<i+1<<" - ";
		cin>>num;
		mySet.insert(num);
	}
	cout<<"Elements of the set are - ";
	for(int i : mySet){
		cout<<i<<" ";
	}
	cout<<endl;
	return 0;
}
