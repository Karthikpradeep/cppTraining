#include<iostream>

using namespace std;

class Rectangle{
	private:
		int length;
		int width;
	public:
		Rectangle() :length(0),width(0){}//initialisation list

		Rectangle(int l,int w){
			length = l;
			width = w;
		}

		int getLength(){
			return length;
		}
		int getWidth(){
			return width;
		}

};

int main(){
	Rectangle r1;
	cout<<"This is the value using default constructor"<<endl;
	cout<<"Length - "<<r1.getLength()<<endl;
	cout<<"Width - "<<r1.getWidth()<<endl;

	Rectangle r2(2,3);
	cout<<"\nThis is the value using parameterized constructor"<<endl;
	cout<<"Length - "<<r2.getLength()<<endl;
	cout<<"Width - "<<r2.getWidth()<<endl;
	cout<<endl;
	return 0;
}
