#include <iostream>
using namespace std;

// Fast Exponentiation: O(logN) time complexity...

int exponentiation(int a, int n)
{
    int ans = 1;
    while (n > 0)
    {
        if ((n & 1) == 1)
        {
            ans = ans * a;
        }
        a = a * a;
        n = (n >> 1);
    }
    return ans;
}

int main()
{
    int a, n;
    cin >> a >> n;
    cout << exponentiation(a, n) << endl;

    return 0;
}