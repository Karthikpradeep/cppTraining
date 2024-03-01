#include <ProcedureHeader.h>

int main(int argc, char* argv[]){
	try{
		if(argc != 2){
			cerr<<"Usage - "<<argv[0]<<"<argument>"<<endl;
			return 1;
		}
		string filePath = argv[1];
		ProcedureCall pc(filePath);
		pc.connectToDatabase();
		pc.callStoredProcedure();
		pc.displayResult();
	}

	catch(exception& e){
		cerr<<"Error - "<<e.what()<<endl;
	}
	return 0;
}

