#include<iostream>

using namespace std;

class Vehicle{
	virtual void start() = 0;
	virtual void stop() = 0;
};

class Car : public Vehicle{
	public:
		void start(){
			cout<<"Car is starting"<<endl;
		}
		void stop(){
			cout<<"Car is stopping"<<endl;
		}
};

class Motorcycle : public Vehicle{
	public:
		void start(){
			cout<<"Motorcycle is starting"<<endl;
		}
		void stop(){
			cout<<"Motorcycle is stopping"<<endl;
		}
};

int main(){
	Car myCar;
	Motorcycle myBike;

	myCar.start();
	myCar.stop();
	cout<<endl;
	myBike.start();
	myBike.stop();
}
