#include<iostream>

using namespace std;
int square(int i){
    return i*i;
}
int doubling(int j){
	return 2*j;
}
void applyFunction(int array[] ,int (*ptr)(int ele)){
    int size = 6 ;
    for(int i = 0 ; i < size ; i++){
    	cout << ptr(array[i]) << " ";
    }
    cout << endl;
}
int main(){
    int array[] = {1,5,6,2,3,8};
    applyFunction(array , square);
    applyFunction(array, doubling);
}
