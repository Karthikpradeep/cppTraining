#include <ConnectionHeader.h>

int main(int argc, char* argv[]){
	try{
		if(argc != 2){
			cerr<<"Usage: "<<argv[0]<<"arguments"<<endl;
			return 1;
		}
		string filePath = argv[1];
		DatabaseConnector dbCnt(filePath);
		dbCnt.connectToDatabase();
		dbCnt.queryExecution();
		}
	catch(exception& e){
		cerr<<"Error- "<<e.what()<<endl;
		return 1;
	}
	return 0;
}


