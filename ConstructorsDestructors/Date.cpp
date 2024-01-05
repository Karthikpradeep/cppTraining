#include<iostream>

using namespace std;

class Date{
	private:
		int day;
		string month;
		int year;
	public:
		Date():day(0),month("Unknown"),year(0){}//default constructor
		
		Date(int d,string m,int y){
			day = d;
			month = m;
			year = y;
		}
		Date(Date& c){
			day = c.day;
			month = c.month;
			year = c.year;
		
		}


		void display(){
			cout<<"Day - "<<day<<endl;
			cout<<"Month - "<<month<<endl;
			cout<<"Year - "<<year<<endl;
		}
};
int main(){
	Date d1;
	cout<<"This is the default constructor called"<<endl;
	d1.display();

	cout<<"\nThis is the parameterised Constructor called"<<endl;
	Date d2(22,"jan",2024);
	d2.display();
	cout<<"\nThis is a copy constructor call"<<endl;
	Date d3;
	d3=d2;
	d3.display();
}

