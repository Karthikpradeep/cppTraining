#include <fileHeader.h>

int main(int argc, char* argv[]){
	
	if(argc != 2){
		cerr<<"Usage: "<<argv[0]<<"<filename>"<<endl;
	}
	string fName = argv[1]; 
	FileHandling file(fName);
	file.createFile();
	return 0;
}
