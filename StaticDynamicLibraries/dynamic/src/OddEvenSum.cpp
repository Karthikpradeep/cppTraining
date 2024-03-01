#include <sumHeader.h>

OddEvenSum::OddEvenSum():OddSum(0),EvenSum(0){
}

OddEvenSum::~OddEvenSum(){
}

void OddEvenSum::FindEven(){
	for(int i=1;i<=1000;++i){
		if(i%2 == 0){
			EvenSum += i;
		}
	}
}

void OddEvenSum::FindOdd(){
	for(int i=1;i<=1000;++i){
		if(i%2 != 0){
			OddSum += i;
		}
	}
}

void OddEvenSum::Display(){
	cout<<"Sum of Odd Numbers - "<<OddSum<<endl;
	cout<<"Sum of Even numbers - "<<EvenSum<<endl;
}
