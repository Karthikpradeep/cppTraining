#include<iostream>

using namespace std;

int main(){
    int n;
    cout<<"Enter the number - ";
    cin>>n;
    int lastNumber=n%10,num=n;
    
    while(n>=10){
        n=n/10;
    }
    int firstNumber=n;
    cout<<"Sum of first and last digit of the number "<<num<<" is "<<firstNumber+lastNumber<<endl;
    return 0;
}