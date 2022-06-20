#include <iostream>
#include <stack>
using namespace std;

// reverse stack: using only recursion and no extra space.

void insertAtBottom(stack<int> &s, int x)
{
    // base case:
    if (s.empty())
    {
        s.push(x);
        return;
    }

    int n = s.top();
    s.pop();

    insertAtBottom(s,x);

    s.push(n);
    return;
}

void reverseStack(stack<int> &s)
{
    // base case:
    if (s.empty())
    {
        return;
    }
    // store the topmost element and reverse the smaller stack.
    int x = s.top();
    s.pop();

    reverseStack(s);

    // insert x at the bottom.
    insertAtBottom(s, x);
}

int main()
{
    stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    reverseStack(s);

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}