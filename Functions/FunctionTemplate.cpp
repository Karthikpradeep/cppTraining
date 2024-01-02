#include<iostream>

using namespace std;

template<typename T>

T MaxValue(T val1, T val2){
	return val1>val2 ? val1:val2;
}

int main(){
	cout<<MaxValue<int>(2,10)<<endl;
	cout<<MaxValue<double>(9.99,8.87)<<endl;
	cout<<MaxValue<char>('a','c')<<endl;
	return 0;
}
