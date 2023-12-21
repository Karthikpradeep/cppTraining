#include <iostream>

using namespace std;

void test(){
	static int var1 = 1;
	int var2 = 1;
	var1++;
	var2++;

	cout<<"static var value - "<<var1<<endl;
	cout<<"Non static var Value - "<<var2<<endl;
}

int main(){
	test();
	test();
	test();
	return 0;
}
