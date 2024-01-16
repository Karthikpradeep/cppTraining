#include <iostream>
#include <vector>

using namespace std;

int main(){
	//types of declaration in vector
	vector <float> vec1 = {1.99,2.69,3.666,4.9};//initilizer list
	vector <int> vec2 {0,9,2};//uniform initilizer
	vector <char> vec3(3,'a');//This will declare a vector of size 3 filled with a's

	for(float i : vec1){
		cout<<i<<" ";
	}
	cout<<endl;
	for(int i : vec2){
		cout<<i<<" ";
	}
	cout<<endl;
	for(char i : vec3){
		cout<<i<<" ";
	}
	cout<<endl;
}
