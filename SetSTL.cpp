#include <iostream>
#include <set>
#include <climits>
using namespace std;

// Set STL: sorted by default...
// ---> uses BST or Red-Black Tree (kinda self balancing BST)

int main()
{
    int arr[] = {10, 20, 30, 30, 10, 20, 45, 9809, 857, 100, 10, 20};
    int n = sizeof(arr) / sizeof(int);

    set<int> s;

    // insertion:
    for (int i = 0; i < n; i++)
    {
        s.insert(arr[i]);
    }

    // erase: accept address or value...erase all occurences of that element.
    s.erase(10);
    auto it = s.find(20);
    s.erase(it);

    // for (set<int>::iterator it = s.begin(); it != s.end(); it++)
    // {
    //     cout << (*it) << " ";
    // }
    // cout << endl;

    unordered_set<pair<int, int>> sp;

    sp.insert(make_pair(10, 2));
    sp.insert(make_pair(40, 1));
    sp.insert(make_pair(10, 3));
    sp.insert(make_pair(30, 2));
    sp.insert(make_pair(30, 3));
    sp.insert(make_pair(30, 1));
    sp.insert(make_pair(40, 2));
    sp.insert(make_pair(20, 1));
    sp.insert(make_pair(20, 2));
    sp.insert(make_pair(20, 3));
    sp.insert(make_pair(10, 1));

    sp.erase(sp.find(make_pair(20, 2)));

    for (auto x : sp)
    {
        cout << x.first << " and " << x.second << endl;
    }
    cout << endl;

    // upper and lower bound returns addresses.
    auto alpha = sp.upper_bound(make_pair(10, INT_MAX)); // if we want first value to be greater 10...
    cout << alpha->first << " and " << alpha->second << endl;

    return 0;
}