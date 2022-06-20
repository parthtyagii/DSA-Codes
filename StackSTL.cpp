#include <iostream>
#include <stack>
using namespace std;

// Stack STL: basic functions

int main()
{
    stack<string> s;

    s.push("parth");
    s.push("vansh");
    s.push("rahul");
    s.push("rhythm");
    s.push("nilesh");

    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }

    return 0;
}