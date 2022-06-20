#include <iostream>
#include <vector>
using namespace std;

// Vector class: introduction

int main()
{
    // Ways to create and initialize vector:
    vector<int> a;
    vector<int> b(5, 0); // vector size = 5 and initializing with " 0 ".
    vector<int> c(b.begin(), b.end());
    vector<int> d{1, 2, 3, 4, 5};

    // iterate over vector:
    for (int i = 0; i < d.size(); i++)
    {
        cout << d[i] << ",";
    }
    cout << endl;

    for (vector<int>::iterator it = d.begin(); it != d.end(); it++) // iterator class
    {
        cout << (*it) << ",";
    }
    cout << endl;

    for (auto x : d) // for each loop
    {
        cout << x << ",";
    }
    cout << endl;

    // intput in a vector:
    vector<int> v;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << ",";
    }
    cout << endl;

    // understanding at memory level, differences in vectors:

    cout << v.size() << endl;     // number of elements in array.
    cout << v.capacity() << endl; // size of underlying array.
    cout << v.max_size() << endl; // max size possible according to the memory availability..

    cout << d.size() << endl;
    cout << d.capacity() << endl;
    cout << d.max_size() << endl;

    return 0;
}
