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
    
    cout<<"\nElements of the vector array is - ";
    for(int i=0;i<vect1.size();i++){
        cout<<vect1[i]<<" ";
    }
    cout<<"\nPoping last element of the vector array  "<<endl;
    vect1.pop_back();
    cout<<"Elements of the vector array after poping last element - ";
    for(int i=0;i<vect1.size();i++){
        cout<<vect1.at(i)<<" ";
    }
    cout<<endl;

    return 0;
}

