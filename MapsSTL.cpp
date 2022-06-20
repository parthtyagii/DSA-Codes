#include <iostream>
#include <string>
#include <map>
using namespace std;

// Maps STL: uses self balancing BST....
// ###### --> All the operations are similiar for unordered map as well.

int main()
{
    // insertion types:
    map<string, int> m;

    m.insert(make_pair("banana", 90));

    pair<string, int> p;
    p.first = "apple";
    p.second = 450;
    m.insert(p);

    m["mango"] = 365;

    // search:
    auto f = m.find("peach"); // returns an iterator..
    if (f != m.end())
    {
        cout << "Price of banana " << m["banana"] << endl;
    }
    else
    {
        cout << "not present!!" << endl;
    }

    if (m.count("banana")) // similiar to find...but returns 0 or 1.
    {
        cout << "Price of banana " << m["banana"] << endl;
    }
    else
    {
        cout << "not present!!" << endl;
    }

    // erase:
    m.erase("banana");
    if (m.count("banana")) // similiar to find...but returns 0 or 1.
    {
        cout << "Price of banana " << m["banana"] << endl;
    }
    else
    {
        cout << "not present!!" << endl;
    }

    // update value:
    m["apple"] += 1000;

    m["lichi"] = 655;
    m["pineapple"] = 748;
    m["plum"] = 918;

    // iteration:
    for (auto it = m.begin(); it != m.end(); it++)
    {
        cout << it->first << " --> " << it->second << endl;
    }
    cout << endl;

    for (auto p : m)
    {
        cout << p.first << " --> " << p.second << endl;
    }

    return 0;
}