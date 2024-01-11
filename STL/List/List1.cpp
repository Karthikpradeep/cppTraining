#include <iostream>
#include <list>

using namespace std;

int main()
{
    list<int> l1 = {1, 2, 3, 4};
    list<int> l2;
    list<int> l3;
    l2.push_back(20);
    l2.push_front(10);
    l2.push_back(30);
    l2.push_back(40);

    list<int>::iterator iter;
    for (int i : l1)
    {
        cout << i << " ";
    }
    cout << endl;
    for (iter = l2.begin(); iter != l2.end(); iter++)
    {
        cout << *iter << " ";
    }
    cout<<endl;
    iter = l2.begin();
    advance(iter,2);
    cout<<"Second element of the list - "<<*iter<<endl;
    cout << endl;
    cout << "Enter value to the list and type -1111 to exit " << endl;
    bool check = true;
    int i = 1, element;
    while (check)
    {
        cout << "Enter element " << i << " - ";
        cin >> element;
        if (element != -1111)
        {
            l3.push_back(element);
            i++;
        }
        else
        {
            check = false;
        }
    }
    //l3.reverse();
    //l3.sort();
    l3.merge(l2);       
    for(int i : l3){
        cout<<i<<" ";
    }
    
    cout<<endl;

    return 0;
}
