#include <iostream>
#include <set>
using namespace std;

// Multi-Set with Custom Class:

class pair_compare
{
public:
    bool operator()(pair<string, int> p1, pair<string, int> p2)
    {
        return p1.second < p2.second;
    }
};

int main()
{
    pair<string, int> p1 = make_pair("A", 253);
    pair<string, int> p2 = make_pair("B", 123);
    pair<string, int> p3 = make_pair("C", 215);
    pair<string, int> p4 = make_pair("D", 90);

    multiset<pair<string, int>, pair_compare> m;
    m.insert(p1);
    m.insert(p2);
    m.insert(p3);
    m.insert(p4);

    for (auto x : m)
    {
        cout << x.first << " - " << x.second << endl;
    }

    return 0;
}