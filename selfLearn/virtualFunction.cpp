#include<iostream>

using namespace std;

class Animals{
	public:
		virtual void display(){
			cout<<"Animals have consciousness"<<endl;
		}
};

class Cat : public Animals{
	public:
		void display(){
			cout<<"Cat's are curious"<<endl;
		}
};

int main(){
	Animals* ptr;
	Animals a;
	Cat c;
	
	ptr = &c;
	ptr->display(); //if we are not using virtual fuction the display method of the base class will be called.
}

