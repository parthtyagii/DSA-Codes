#include <iostream>
using namespace std;

// iterative approach:
int GCD1(int a, int b)
{
    int x = min(a, b);
    int y = max(a, b);
    while (x > 0)
    {
        int alpha = x;
        x = y % x;
        y = alpha;
    }
    return y;
}

// Recursive Method:
int GCD2(int a, int b)
{
    int x = min(a, b);
    int y = max(a, b);
    if (x == 0)
    {
        return y;
    }
    return GCD2(y % x, x);
}

int main()
{
    int a, b;
    cin >> a >> b;

    cout << "GCD1 of a and b: " << GCD1(a, b) << endl;
    cout << "GCD2 of a and b: " << GCD2(a, b) << endl;
    cout << "LCM of a and b: " << ((a * b) / GCD1(a, b)) << endl;

    return 0;
}