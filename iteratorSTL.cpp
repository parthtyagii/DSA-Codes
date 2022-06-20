#include <iostream>
#include <string>
#include <vector>
using namespace std;

// how generic programmes works in STL:
// templates + iterators + comparators:
// tempaltes: not data-type specific programmes
// iterators: not container specific programmes.

class car
{

public:
    int price;
    string name;

    car() {}
    car(string name, int price)
    {
        (this)->name = name;
        (this)->price = price;
    }
};

class compare
{
public:
    compare() {}
    bool operator()(car a, car b) // also knows as "functors".
    {
        if (a.price == b.price)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

template <typename address, class com>
address search(address start, address end, car k, com comp)
{
    while (start != end)
    {
        if (comp(*start, k))
        {
            return start;
        }
        else
        {
            start++;
        }
    }

    return start;
}

int main()
{
    car c1("maruti", 100);
    car c2("BMW", 200);
    car c3("ferrari", 300);
    car c4("porsche", 400);

    car c5("anonymous", 300);

    vector<car> v;
    v.push_back(c1);
    v.push_back(c2);
    v.push_back(c3);
    v.push_back(c4);

    compare obj;

    vector<car>::iterator it = search(v.begin(), v.end(), c5, obj);
    if (it != v.end())
    {
        cout << "car found: " << (it)->name << endl;
    }
    else
    {
        cout << "car not found" << endl;
    }
}
