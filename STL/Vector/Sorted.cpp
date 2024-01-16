#include<iostream>
#include<vector>

using namespace std;

bool SortCheck(vector<int> vect){
	bool isSorted = true;
	for(int i=0;i<vect.size()-1;i++){
		if(vect.at(i)>vect.at(i+1)){
				isSorted = false;
				break;
			}
	}
	return isSorted;
}	

int main(){
	vector<int> vect;
	int size,element;
	cout<<"Enter the size - ";
	cin>>size;

	cout<<"Enter the elements to vector "<<endl;
	for(int i=0;i<size;i++){
		cout<<"Element "<<i+1<<" - ";
		cin>>element;
		vect.push_back(element);
	}
	bool isSort = SortCheck(vect);
	if(isSort){
		cout<<"The vector is sorted "<<endl;
	}
	else{
		cout<<"The vector is not sorted"<<endl;
	}
	return 0;
}

