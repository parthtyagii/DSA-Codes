#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// Phone Book:

int main()
{
    unordered_map<string, vector<int>> phonebook;
    phonebook["parth"].push_back(889);
    phonebook["parth"].push_back(576);
    phonebook["parth"].push_back(968);
    phonebook["vansh"].push_back(432);
    phonebook["vansh"].push_back(323);
    phonebook["vansh"].push_back(223);

    // iterate:
    for (auto p : phonebook)
    {
        cout << p.first << " -> ";
        for (auto x : p.second)
        {
            cout << x << ", ";
        }
        cout << endl;
    }

    return 0;
}