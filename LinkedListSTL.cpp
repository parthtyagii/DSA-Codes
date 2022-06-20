#include <iostream>
#include <list>
#include<forward_list>
using namespace std;

// List STL: (doubly linked list)

int main()
{
    // initialize
    list<int> l1{4, 1, 15, 77, 10, 5};

    //add and remove front and back
    l1.push_back(1);
    l1.pop_back();

    l1.push_front(55);
    l1.pop_front();

    // sort:
    l1.sort();

    // reverse:
    l1.reverse();

    cout << l1.front() << endl;
    cout << l1.back() << endl;

    // iterate:
    for (auto x : l1)
    {
        cout << x << " ";
    }
    cout << endl;

    for (list<int>::iterator it = l1.begin(); it != l1.end(); it++)
    {
        cout << (*it) << " ";
    }
    cout << endl;

    l1.push_back(12);
    l1.push_front(12);
    l1.push_back(12);
    l1.push_front(12);
    l1.push_back(12);
    l1.push_front(12);
    l1.push_back(12);
    l1.push_front(12);
    l1.push_back(12);
    l1.push_front(12);

    for (auto x : l1)
    {
        cout << x << " ";
    }
    cout << endl;

    // remove: delete all occurences of that element
    int n;
    cin >> n;
    l1.remove(n);

    for (auto x : l1)
    {
        cout << x << " ";
    }
    cout << endl;

    // erase: delete at particular index.
    auto idx = l1.begin();
    idx++;
    idx++;
    l1.erase(idx);

    for (auto x : l1)
    {
        cout << x << " ";
    }
    cout << endl;

    // insert: insert at particular position
    auto idx2 = l1.begin();
    idx2++;
    idx2++;
    l1.insert(idx2, 1000);`

    for (auto x : l1)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
