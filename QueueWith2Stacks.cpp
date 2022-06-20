#include <iostream>
#include <stack>
using namespace std;

// Building Queue using 2 Stacks(only).

template <typename t>
class Queue
{

    stack<t> s1;
    stack<t> s2;

public:
    void Push(t d)
    {
        s1.push(d);
        return;
    }

    void Pop()
    {
        if (!s1.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }

            s2.pop();

            while (!s2.empty())
            {
                s1.push(s2.top());
                s2.pop();
            }
        }
        return;
    }

    t Top()
    {
        if (!s1.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }

            t element = s2.top();

            while (!s2.empty())
            {
                s1.push(s2.top());
                s2.pop();
            }

            return element;
        }
    }

    bool Empty()
    {
        return s1.empty();
    }
};

int main()
{
    Queue<int> q;

    q.Push(1);
    q.Push(2);
    q.Push(3);
    q.Push(4);
    q.Push(5);

    q.Pop();
    q.Pop();

    q.Push(6);
    q.Push(7);

    while (!q.Empty())
    {
        cout << q.Top() << " ";
        q.Pop();
    }

    return 0;
}