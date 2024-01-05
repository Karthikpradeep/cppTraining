#include<iostream>

using namespace std;

class Shape{
	protected:
		int width;
		int height;
	public:
		Shape(int w,int h){
			width=w;
			height=h;
		}
		virtual void display(){
			cout<<"Area of shapes"<<endl;
		}
};

class Rectangle : public Shape{
	public:
		Rectangle(int w,int h) : Shape(w,h){}
		void calculateArea(){
			cout<<"Area of the rectangle is "<<width*height<<endl;
		}
		void display(){
			calculateArea();
		}
};

class Triangle : public Shape{
	public:
		Triangle(int w,int h) : Shape(w,h){}
		void calculateArea(){
			cout<<"Area of the Triangle is "<<0.5*width*height<<endl;
		}
		void display(){
			calculateArea();
		}
};

int main(){
	Shape* ptr[2];
	ptr[0] = new Rectangle(2,4);
	ptr[1] = new Triangle(2,3);
	for(auto i : ptr){
		i->display();
	}
}
