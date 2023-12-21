#include <iostream>

using namespace std;
int main(){
    int n,sum =0;
    cout<<"Enter the value - ";
    cin>>n;

    cout<<"First "<<n<<" natural numbers are - "<<endl;
    for(int i=1;i<=n;i++){
        cout<<i<<" ";
        sum+=i;
    }

    cout<<"\nSum of first "<<n<<" natural numbers is "<<sum<<endl;

    return 0;
}