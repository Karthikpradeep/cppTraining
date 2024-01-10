#include<iostream>

using namespace std;

int main(){

    int x = 4; //static memory

    int* ptr = new int;
    *ptr = 5;
    cout<<"ptr - "<<ptr<<endl;
    cout<<"*ptr - "<<*ptr<<endl;//this causes memory leak
    //ptr = new int(10);
    //cout<<"ptr - "<<ptr<<endl;
    //cout<<"*ptr - "<<*ptr<<endl;

    // dynamic memory allocation for the array of elements

    double *array = new double(4);
    array[0] = 323.23;
    array[1] = 2.1;
    array[2] = 33.1;
    array[3] = 123.22;

    cout<<"Data in array "<<endl;
    for(int i=0;i<4;i++){
        cout<<"array ["<<i<<"] = "<<array[i]<<endl;
    }
    
    delete[] array;
    delete ptr;

}
