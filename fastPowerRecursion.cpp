#include <iostream>
using namespace std;

// O(logN) time and and space:

int power(int a, int n)
{
    if (n == 0)
    {
        return 1;
    }
    return (a * power(a, n - 1));
}

int Fastpower(int a, int n)
{
    if (n == 0)
    {
        return 1;
    }
    int sub = Fastpower(a, n / 2);
    sub *= sub;
    if (n & 1)
    {
        sub = sub * a;
        return sub;
    }
    return sub;
}

int main()
{
    int a, n;
    cin >> a >> n;

    cout << power(a, n) << " <--- basic approach" << endl;
    cout << Fastpower(a, n) << " <--- more optimised approach" << endl;

    return 0;
}