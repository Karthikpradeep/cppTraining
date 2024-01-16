#include<iostream>
#include<vector>
#include<map>

using namespace std;

int main(){
	vector<int> myVect = {1,2,5,12,1,4,2,5};

	cout<<"Values of the vector is - ";
	for(int i : myVect){
		cout<<i<<" ";
	}

	map<int, int> Occurences;

	for(const auto element : myVect){
		Occurences[element]++;
	}

	cout<<"\n Occurences of each element in the map is "<<endl;
	for(const auto element : Occurences){
		cout<<element.first<<" = "<<element.second<<""<<endl;
	}

	return 0;
}
