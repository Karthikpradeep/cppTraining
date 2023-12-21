#include <iostream>

using namespace std;
int prime(int num){
    if(num <=1){
        return 0;
    }

    for(int i=2;i<=num;i++){
        for(int j=2;j<i;j++){
            if(num%j==0){
                return 0;
            }
            else
            {
                return 1;
            }
        }
    }
    return 1;
    
}

int main(){
    int n;
    int lastPrime=2;
    cout<<"Enter the number - ";
    cin>>n;

    for(int i=2;i<n;++i){
        if(prime(i) == 1){
            lastPrime = i;
        }
    }
    cout<<"Last Prime number is - "<<lastPrime<<endl;
}