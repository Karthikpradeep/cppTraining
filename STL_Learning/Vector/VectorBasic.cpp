#include<iostream>
#include<vector>

using namespace std;

int main(){
    vector<int> vect1;
    int size,element;
    cout<<"Enter the size of the array - ";
    cin>>size;

    cout<<"Enter the elements of the array "<<endl;
    for(int i=0;i<size;i++){
        cin>>element;
        vect1.push_back(element);
    } 
    
    cout<<"Elements of the array - ";
    for(int i=0;i<vect1.size();i++){
        cout<<vect1[i]<<" ";
    }
    
    cout<<endl;
    return 0;
}
