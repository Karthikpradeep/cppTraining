#include <iostream>
#include <cmath>

using namespace std;

void add(int length, int breadth){
	cout<<"Area of the rectangle is - "<<length*breadth<<endl;
}

void add(int radius){
	float area = 3.14*pow(radius, 2);
	cout<<"Area of the circle is - "<<area<<endl;
}
int main(){
	int length,breadth,radius;
	cout<<"Enter length and breadth of rectangle to find the area"<<endl;
	cout<<"Enter the length of the rectangle - ";
	cin>>length;
	cout<<"Enter the breadth of the rectangle - ";
	cin>>breadth;

	cout<<"Enter the radius of the circle to find the area - ";
	cin>>radius;
	add(length, breadth);
	add(radius);

	return 0;
}


