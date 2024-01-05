#include<iostream>

using namespace std;

class Shape{
public:
	int width;
	int height;
	Shape(int w,int h){
		width = w;
		height = h;
	}
	
};

class Rectangle : public Shape{
public:
	Rectangle(int w,int b)
		:Shape(w,b){}

	void area(){
		cout<<"Area of the circle - "<<width*height<<endl;
	}
	

};
class Triangle : public Shape{
public:
	Triangle(int w, int h)
		:Shape(w,h){}
	void area(){
		cout<<"Area of the Triangle - "<<0.5*width*height<<endl;
	}
};

int main(){
	Rectangle rect = Rectangle(2,4);
	rect.area();
	Triangle tri = Triangle(5,15);
	tri.area();
}

