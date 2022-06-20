#include <iostream>
#include <set>
using namespace std;

// MultiSet: can store multiple elements having same value.
// elements stored in specific order: sorted according to internal comparison.
// values can't be modified.
// associative container --> elements are refered by their values and not by address.
// underlying implementation uses --> BST

int main()
{
    int arr[] = {10, 20, 30, 40, 20, 10, 10, 20, 50, 60, 70, 80, 90};
    int n = sizeof(arr) / sizeof(int);

    multiset<int> m(arr, arr + n);
    m.insert(100);

    // erase:
    // m.erase(20);

    // find:
    auto fd = m.find(30);
    cout << (*fd) << endl;

    // iterate:
    for (auto x : m)
    {
        cout << x << " ";
    }
    cout << endl;

    // count:
    cout << m.count(20) << endl;

    // range of a number: second pointer points to just next element to last occurence of given element.
    pair<multiset<int>::iterator, multiset<int>::iterator> range = m.equal_range(20);

    for (auto it = range.first; it != range.second; it++)
    {
        cout << (*it) << " ";
    }
    cout << endl;

    // upper and lower bound:
    for (auto it = m.lower_bound(30); it != m.upper_bound(90); it++)
    {
        cout << (*it) << " ";
    }
    cout << endl;

    return 0;
}