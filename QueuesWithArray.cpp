#include <iostream>
using namespace std;

// Queues: implementaion using array.

class Queue
{
    int *arr;
    int f, r, ms, cs;

public:
    Queue(int size = 5)
    {
        arr = new int[size];
        f = 0;
        r = size - 1;
        ms = size;
        cs = 0;
    }

    bool empty()
    {
        return cs == 0;
    }

    bool full()
    {
        return cs == ms;
    }

    void push(int data)
    {
        if (!full())
        {
            r = (r + 1) % ms;
            arr[r] = data;
            cs++;
        }
    }

    void pop()
    {
        if (!empty())
        {
            f = (f + 1) % ms;
            cs--;
        }
    }

    int front()
    {
        return arr[f];
    }

    ~Queue()
    {
        if (arr != NULL)
        {
            delete[] arr;
            arr = NULL;
        }
    }
};

int main()
{
    Queue q;

    for (int i = 1; i < 8; i++)
    {
        q.push(i);
    }

    q.pop();
    q.pop();

    q.push(10);
    q.push(20);

    cout << q.front() << endl;

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}