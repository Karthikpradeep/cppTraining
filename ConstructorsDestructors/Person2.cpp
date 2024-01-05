#include<iostream>

using namespace std;

class Person{
    private:
        string name;
        int age;
        char gender;
	static int count;
    public:
        //default constructor
        Person(){
            ++count;
	    cout<<"Person object p"<<count<<" created "<<endl;
            name = "Unknown";
            age = 0;
            gender = 'U';
        }

        //Parameterized Constructor
        Person(string Name, int Age, char Gender){
            ++count;
	    cout<<"Person object p"<<count<<" created "<<endl;

            name = Name;
            age = Age;
            gender = Gender;
        }

        //Copy Constructor
        Person(Person &obj){
            ++count;
	    cout<<"Person object p"<<count<<" created "<<endl;

            name = obj.name;
            age = obj.age;
            gender = obj.gender;
        }
        void display(){
            cout<<"\nName - "<<name<<endl;
            cout<<"Age - "<<age<<endl;
            cout<<"gender - "<<gender<<endl;
        }
        ~Person(){
            cout<<"Destructor called for the objects p"<<count<<endl;
            count--;
        }

};
int Person :: count =0;
int main(){
    //multiple objects with different parameters
    Person p1,p2("Meenu",22,'F'),p3("Ravi",25,'M');
    p1.display();
    p2.display();
    p3.display();

    Person p4 = p2;//copy constructor is called
    p4.display();
    return 0;
}

