// 1--Unique elements
// 2--Immutable
// 3--Sorted order(Default ascending)
// 4--Associative

#include <iostream>
#include <set>

using namespace std;

int main()
{
    int size, element;
    set<int, greater<int>> set1 = {10, 2, 4, 1, 100, 0}; // descending order set
    set<int> set2;                                       // Empty set

    for (int i : set1)
    {
        cout << i << " ";
    }
    cout << endl;

    // Adding elements to the set
    cout << "Enter the number of elements - ";
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        cout << "Enter element " << i + 1 << " - ";
        cin >> element;
        set2.insert(element);
    }
    cout << endl;
    for (int i : set2)
    {
        cout << i << " ";
    }
    cout << endl;

    // deleting values from a set
    set1.erase(100);
    for (int i : set1)
    {
        cout << i << " ";
    }
    cout << endl;
    // check if the set is empty
    cout << "Empty set1 - " << set1.empty() << endl; // 0 means false
    // check the size of the set
    cout << "Set1 size - " << set1.size() << endl;
    // clear the values in the set
    set1.clear();
    cout << "Values of the set1 - ";
    for (int i : set1)
    {
        cout << i << " ";
    }
    cout<<endl;
    cout << "Size of the set1 - " << set1.size() << endl;

    return 0;
}
