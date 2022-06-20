#include <iostream>
using namespace std;

void decreasing(int n)
{
    if (n == 0)
    {
        return;
    }

    // code before recursive call is Top to Bottom.
    cout << n << " ";
    decreasing(n - 1);
}

void increasing(int n)
{
    if (n == 0)
    {
        return;
    }

    // code after recursive call is Bottom to Top.
    increasing(n - 1);
    cout << n << " ";
}

int main()
{
    int n;
    cin >> n;

    decreasing(n);
    cout << endl;
    increasing(n);

    return 0;
}