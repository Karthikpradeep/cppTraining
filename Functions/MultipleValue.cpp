#include<iostream>

using namespace std;

pair<int, int> calculateRectangle(int length, int breadth){
	int area = length*breadth;
	int perimeter = 2*(length+breadth);

	return {area,perimeter};
}
int main(){
	int length,breadth;
	cout<<"Enter the length of the rectangle - ";
	cin>> length;
	cout<<"Enter the breadth of the rectangle - ";
	cin>>breadth;

	pair<int,int> result = calculateRectangle(length,breadth);
	cout<<"Area of the rectangle - "<<result.first<<endl;
	cout<<"Perimeter of the rectangle - "<<result.second<<endl;

	return 0;
}

