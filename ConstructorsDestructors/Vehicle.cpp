#include<iostream>

using namespace std;

class Vehicle{
	public:
	Vehicle(){
		cout<<"Vehicle constructor called"<<endl;
	}

	~Vehicle(){
		cout<<"Vehicle destructor called"<<endl;
	}
};

class Car : public Vehicle{
	public:
	Car(){
		cout<<"Car constructor called"<<endl;
	}
	~Car(){
		cout<<"Car destructor called"<<endl;
	}
};

int main(){
	cout<<"car object created"<<endl;
	Car c1;
	cout<<"Another car object created"<<endl;
	Car c2;
}

