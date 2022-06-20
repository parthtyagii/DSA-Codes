#include <iostream>
using namespace std;

void generateBrackets(int n, char *output, int i, int open, int close)
{
    if (i == 2 * n)
    {
        output[i] = '\0';
        cout << output << endl;
        return;
    }

    if (open < n)
    {
        output[i] = '(';
        generateBrackets(n, output, i + 1, open + 1, close);
    }

    if (close < open)
    {
        output[i] = ')';
        generateBrackets(n, output, i + 1, open, close + 1);
    }

    return;
}

int main()
{
    int n;
    cin >> n;

    char output[1000];
    int i;

    generateBrackets(n, output, 0, 0, 0);

    return 0;
}