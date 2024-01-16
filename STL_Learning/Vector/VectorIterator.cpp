#include<iostream>
#include<vector>

using namespace std;

int main(){
    vector<int> vect = {22,10,20,12,98};

    vector<int> :: iterator iter; // iterator points to the memory address of an vector element
    //iter = vect.begin();
    //cout<<*iter<<endl;

    for(iter = vect.begin();iter != vect.end();iter++){
        cout<<*iter<<" ";
    }
    cout<<endl;

    return 0;

}
