#include <fileHeader.h>

int main(int argc, char* argv[]){

	if(argc != 2){
		cerr<<"usage : "<<argv[0]<<"<filename>"<<endl;
	}
	string fname = argv[1];
	FileWriting file(fname);
	file.WritingToFile();
	return 0;
}	
