#include<iostream>

using namespace std;

class myCustomException : public exception{
    public:
        const char * what(){
            return "Custom exception";
        }
};

int main(){
    try{
        throw myCustomException();
    }
    catch(myCustomException ex){
        cout<<"Exception occured "<<endl;
        cout<<ex.what()<<endl;
    }

    return 0;
}
