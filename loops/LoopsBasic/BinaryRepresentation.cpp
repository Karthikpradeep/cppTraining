#include<iostream>

using namespace std;

int main(){
    int num;
    cout<<"Enter the number to find binary - ";
    cin>>num;
    int binary[64];
    int i=0;
    while(num>0){
        binary[i]=num%2;
        num=num/2;
        i++;
    }

    for(int j=i-1;j>=0;j--){
        cout<<binary[j];
    }
    cout<<endl;

    return 0;
}