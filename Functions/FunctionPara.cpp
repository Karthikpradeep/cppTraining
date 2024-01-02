#include <iostream>

using namespace std;

int calculateArea(int length, int breadth){
	int area = length*breadth;

	return area;
}
int main(){
	int length, breadth,area;
	cout<<"Enter the length of the rectangle - ";
	cin>>length;
	cout<<"Enter the breadth of the rectangle - ";
	cin>>breadth;

	area= calculateArea(length,breadth);
	cout<<"The area of rectangle is - "<<area<<endl;

	return 0;
}
