#include<iostream>
#include<vector>

using namespace std;

void SumAverage(vector<int> vect){
	int sum=0,average;
	for(int i=0;i<vect.size();i++){
		sum += vect.at(i);
	}

	cout<<"Sum of values in the vector is - "<<sum<<endl;
	cout<<"Average is - "<<sum/vect.size()<<endl;
}
int main(){
	vector<int> vect;
	int size,element;
	cout<<"Enter the size of the array - ";
	cin>>size;

	cout<<"Enter the elements of the array "<<endl;
	for(int i=0;i<size;i++){
		cout<<"Element "<<i+1<<" - ";
		cin>>element;
		vect.push_back(element);
	}
	SumAverage(vect);

	return 0;
}




