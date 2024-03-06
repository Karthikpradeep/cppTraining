#include <fileHeader.h>

int main(int argc, char* argv[]){
	if(argc != 2){
		cerr<<"Wrong number of arguments"<<endl;
	}
	string fName = argv[1];
	FileReader file(fName);
	file.ReadingFile();
	return 0;
}
