#include<iostream>

using namespace std;

class OverSpeed{
	private:
		int speed;
	public:
		const char * what(){
			return "!!! High speed alert !!!";
		}

		void setSpeed(int speed){
			this->speed = speed;
		}

		void getSpeed(){
			cout<<"Your speed is "<<speed<<endl;
		}
};

class Car{
	private:
		int speed;
	public:
		Car(){
			speed = 0;
			cout<<"Speed is "<<speed<<endl;
		}

		void accelerate(){
			for(;;){
				speed += 10;
				cout<<"Speed is "<<speed<<endl;

				if(speed >= 220){
					OverSpeed s;
					s.setSpeed(speed);
					throw s;
				}
			}
		}
};

int main(){
	Car myCar;
	try{
		myCar.accelerate();
	}
	catch(OverSpeed s){
		cout<<s.what()<<endl;
		s.getSpeed();
	}

	return 0;
}
				
