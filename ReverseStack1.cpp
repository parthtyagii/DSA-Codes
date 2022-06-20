#include <iostream>
#include <stack>
using namespace std;

// reverse stack: using only one extra stack.

void transfer(stack<int> &s1, stack<int> &s2, int n)
{
    for (int i = 0; i < n; i++)
    {
        s2.push(s1.top());
        s1.pop();
    }
}

void reverse(stack<int> &s1)
{
    // helper stack:
    stack<int> s2;
    int n = s1.size();

    for (int i = 0; i < n-1; i++)
    {
        // save the top element:
        int x = s1.top();
        s1.pop();

        // transfer n-i-1 elements from s1 to s2.
        transfer(s1, s2, n - i - 1);

        // push x to s1.
        s1.push(x);

        // transfer n-i-1 elements from s2 to s1.
        transfer(s2, s1, n - i - 1);
    }
}

int main()
{
    stack<int> s1;

    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);

    reverse(s1);

    while (!s1.empty())
    {
        cout << s1.top() << " ";
        s1.pop();
    }

    return 0;
}