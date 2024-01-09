#include<iostream>

using namespace std;

int main(){
	try{
		int* arr = new int[9999999999999999];
	}
	/*catch(bad_alloc& e){
		cout<<"Exception: "<<e.what()<<" Occured"<<endl;
	}*/
	catch(exception& e){
		cout<<"Exception: "<<e.what()<<" Occured"<<endl;
	}


	return 0;
}
