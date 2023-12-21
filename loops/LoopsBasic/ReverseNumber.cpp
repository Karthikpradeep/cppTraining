#include <iostream>

using namespace std;

int main(){
    int n,num;

    cout<<"Enter the number - ";
    cin>>n;
    cout<<"Reveresed number is - ";
    while(n!=0){
        num=n%10;
        cout<<num;
        n=n/10;
    }
}