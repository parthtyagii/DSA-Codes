#include <iostream>
using namespace std;

int main()
{
    int n1 = 85;
    int n2 = 85;
    int n3 = 85;

    // First method:
    int ans1 = 0;
    while (n1 > 0)
    {
        ans1 += (n1 & 1);
        n1 = n1 >> 1;
    }
    cout << ans1 << endl;

    // Second method: slightly more efficient than first method.
    int ans2 = 0;
    while (n2 > 0)
    {
        n2 = n2 & (n2 - 1);
        ans2++;
    }
    cout << ans2 << endl;

    // Third method (built in function): most efficient among the three methods.
    cout << __builtin_popcount(n3) << endl;

    return 0;
}