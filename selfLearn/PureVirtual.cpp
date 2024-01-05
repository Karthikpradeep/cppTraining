#include<iostream>

using namespace std;

class Food{
public:
	virtual void taste() = 0;//pure virtual functions or do nothing functions
};

class Biriyani : public Food{
public:
	void taste(){
		cout<<"Biriyani is delicious "<<endl;
	}
};

class Roti : public Food{
public:
	void taste(){
		cout<<"Roti is dry"<<endl;
	}
};

int main(){
	Roti r;
	r.taste();
	Biriyani b;
	b.taste();
}
