#include<iostream>
#include<map>

using namespace std;

int main(){
    map<string, int> students= {{"Arjun",99},{"Meenu",69},{"Zain",88}};
    students.insert(make_pair("Kunju",29));//add values
    map<string,int>:: iterator iter;
    //access values
    for(iter = students.begin();iter != students.end();iter++){
        cout<<iter->first<<" "<<(*iter).second<<endl;
    }
    //finding values;
    iter = students.find("Kunju");
    cout<<iter->first<<" "<<iter->second<<endl;
    return 0;

}
