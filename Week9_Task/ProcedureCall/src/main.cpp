#include <ProcedureHeader.h>

int main(){
	try{
	ProcedureCall pc;
	pc.connectToDatabase();
	pc.callStoredProcedure();
	pc.displayResult();
	}

	catch(exception& e){
		cerr<<"Error - "<<e.what()<<endl;
	}
	return 0;
}

