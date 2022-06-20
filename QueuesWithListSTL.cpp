#include <iostream>
#include <list>
using namespace std;

// Queues: implementation List STL.

class Queue
{

    list<int> l;
    int cs;

public:
    Queue()
    {
        cs = 0;
    }

    void push(int d)
    {
        l.push_back(d);
        cs++;
    }

    void pop()
    {
        if (!empty())
        {
            l.pop_front();
            cs--;
        }
    }

    int Front()
    {
        return l.front();
    }

    bool empty()
    {
        return cs == 0;
    }
};

int main()
{
    Queue q;

    for (int i = 1; i <= 10; i++)
    {
        q.push(i);
    }

    q.pop();
    q.pop();
    q.pop();

    cout << q.Front() << endl;

    while (!q.empty())
    {
        cout << q.Front() << " ";
        q.pop();
    }

    return 0;
}