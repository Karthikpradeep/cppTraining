#include<iostream>

using namespace std;

template <typename T, typename U>

class Pair{
    private:
        T length;
        U breadth;
    public:
        void setData(T val1, U val2){
            length = val1;
            breadth = val2;
        }

        T getLength(){
            return length;
        }
        U getBreadth(){
            return breadth;
        }
};
int main(){
    Pair <int,double>obj1;
    obj1.setData(3,4.23);
    cout<<"value of length - "<<obj1.getLength()<<endl;
    cout<<"value of breadth - "<<obj1.getBreadth()<<endl;

    Pair <string,char>obj2;
    obj2.setData("twenty",'5');
    cout<<"value of length - "<<obj2.getLength()<<endl;
    cout<<"value of breadth - "<<obj2.getBreadth()<<endl;
}
