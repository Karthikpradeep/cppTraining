#include <cvheader.h>

CV::CV():balance(0){
}

CV::~CV(){
}

void CV::addMoney(int money){
	lock_guard<mutex> lg(m);
	balance += money;
	cout<<"Money added to current balance - "<<balance<<endl;
	cv.notify_one(); //notify the thread which is waiting for the conditional variable cv
}

void CV::withdrawMoney(int money){
	unique_lock<mutex> ul(m);
	cv.wait(ul, [this] { return (balance!=0) ? true : false ;});
	if(balance >= money){
		balance -= money;
		cout<<"Amount deducted : "<<money<<endl;
	}
	else{
		cout<<"Amount cannot be deducted. Insufficient balance. Current balance is less than"<<money<<endl;
	}
	cout<<"Current balance is - "<<balance<<endl;
}
