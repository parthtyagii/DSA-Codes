#include <iostream>
#include <queue>
using namespace std;

// Building a Stack using 2 queues(only):

template <typename t>
class Stack
{

    queue<t> q1;
    queue<t> q2;

public:
    void push(t d)
    {
        q1.push(d);
        return;
    }

    void pop()
    {
        while (q1.size() > 1)
        {
            q2.push(q1.front());
            q1.pop();
        }

        // last element of q1.
        q1.pop();

        // becoz we want to add element to q1 only.
        swap(q1, q2);
    }

    t top()
    {

        while (q1.size() > 1)
        {
            q2.push(q1.front());
            q1.pop();
        }

        // last element of q1.
        t element = q1.front();
        q1.pop();
        q2.push(element);

        // becoz we want to add element to q1 only.
        swap(q1, q2);

        return element;
    }

    bool Empty()
    {
        return q1.empty();
    }
};

int main()
{
    Stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    s.pop();

    s.push(6);
    s.push(7);
    s.push(8);

    while (!s.Empty())
    {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}