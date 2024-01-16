#include<iostream>
#include<vector>

using namespace std;

int main(){
	vector <int> vect1;
	int size,element;
	cout<<"Enter the size of the array - ";
	cin>>size;

	for(int i=0;i<size;i++){
		cout<<"Element "<<i+1<<" - ";
		cin>>element;
		vect1.push_back(element);
	}
	// push_back() function add elements to a vector
	cout<<"Elements of the array - ";
	for(int i : vect1){
		cout<<i<<" ";
	}
	cout<<endl;
	cout<<"Element at 1st index - "<<vect1.at(1)<<endl; // accessing element 
	//[] also used to acces element if not present it will show garbage value but in .at() shows exception
	//cout<<vect1.at(10)<<endl;

	//change element .at() is used

	//Delete elements
	vect1.pop_back(); // delete last element
	//vect1.pop_front(); //delete first element
	vect1.erase(vect1.begin()+1); // delete element if the index1
	for(int i : vect1){
		cout<<i<<" ";
	}

	cout<<endl;
	return 0;
}
