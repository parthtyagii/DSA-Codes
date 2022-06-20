#include <iostream>
#include <stack>
using namespace std;

// checkng if the parenthesis in the string are balanced or not.

bool checkBrackets(char *arr)
{

    stack<char> s;

    for (int i = 0; arr[i] != '\0'; i++)
    {
        if (arr[i] == '(')
        {
            s.push('(');
        }
        else if (arr[i] == ')')
        {
            if (s.top() != '(')
            {
                return false;
            }
            s.pop();
        }
    }

    return s.empty();
}

int main()
{
    char arr[100] = "((a+b))-(c+d-f))";

    if (checkBrackets(arr))
    {
        cout << "balanced";
    }
    else
    {
        cout << "not balanced";
    }

    return 0;
}