#include <iostream>

using namespace std;

class Student
{
public:
    string name;

    void print()
    {
        cout << "Name - " << name << endl;
    }
    Student(string Name) : name(Name) {}
};
int main()
{
    Student *student = new Student("Rooney");
    //(*student).name = "Jack";
    //(*student).print();
    student->print();

    delete student;
    try
    {
        int *ptr = new int[99999999999999999];

        delete[] ptr;
    }
    catch (bad_alloc &exp)
    {
        cout << "bad_alloc caught - " << exp.what() << endl;
    }
    
}
