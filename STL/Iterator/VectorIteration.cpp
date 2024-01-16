#include<iostream>
#include<vector>

using namespace std;

int main(){
	vector<int> vect;
	int entries,element;
	cout<<"Enter the number of entries - ";
       	cin>>entries;
	
	cout<<"Enter the elements to the vector "<<endl;
	for(int i=0; i<entries;i++){
		cout<<"Element "<<i+1<<" - ";
		cin>>element;
		vect.push_back(element);
	}
	vector<int> :: iterator iter;
	cout<<"\nVector elements - ";
	for(iter = vect.begin();iter != vect.end();++iter){
		cout<<*iter<<" ";
	}
	cout<<endl;
	return 0;
}



