#include<iostream>

using namespace std;

int main(){
	string str = "hello";

	//cout<<str.at(5)<<endl;  out of range exception occurs
	
	try{
		cout<<str.at(5)<<endl;
	}
	catch(out_of_range& e){
		cout<<"Exception: "<<e.what()<<" occured"<<endl;
	}

	return 0;

}
