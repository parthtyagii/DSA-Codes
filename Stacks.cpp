#include <iostream>
#include <vector>
using namespace std;

// Stack: using vector

template <class t>
class stack
{
private:
    vector<t> v;

public:

    void pushback(t data)
    {
        v.push_back(data);
    }

    void popback()
    {
        if (!v.empty())
        {
            v.pop_back();
        }
    }

    t topp()
    {
        return v[v.size() - 1];
    }

    bool Empty()
    {
        if (v.size() == 0)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    stack<int>s;

    for (int i = 1; i <= 10; i++)
    {
        s.pushback(i * i);
    }

    while (!s.Empty())
    {
        cout << s.topp() << " ";
        s.popback();
    }

    return 0;
}