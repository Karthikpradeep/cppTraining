#include <header.h>

UniqueLock::UniqueLock():buffer(0){
}

UniqueLock::~UniqueLock(){
	m.unlock();
}

void UniqueLock::task(const char* threadNumber,int loopfor){
	unique_lock<mutex> lock(m,defer_lock);
	lock.lock();
	for(int i=0;i<loopfor;++i){
		buffer++;
		cout<<threadNumber<<buffer<<endl;
	}
}


