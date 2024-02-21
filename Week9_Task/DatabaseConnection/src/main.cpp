#include <ConnectionHeader.h>

int main(){
	try{
		DatabaseConnector dbCnt;
		dbCnt.connectToDatabase();
		dbCnt.queryExecution();
		}
	catch(exception& e){
		cerr<<"Error- "<<e.what()<<endl;
		return 1;
	}
	return 0;
}


