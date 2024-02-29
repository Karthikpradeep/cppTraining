#include <detachHeader.h>

DetachThread::DetachThread(int count){
}

DetachThread::~DetachThread(){
}

void DetachThread::execute(){
        while(count --> 0){
                cout<<count<<endl;
        }
        sleep(5);
}

