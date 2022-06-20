#include <iostream>
using namespace std;

int fact(int n)
{
    // base case:
    if (n == 0)
    {
        return 1;
    }

    // recursive call:
    int small_n = fact(n - 1); // fuction will pause at this line. And new stack frame is alloted for fact(n-1) and
    int ans = n * small_n;     // this goes on until we reach base case.
    return ans;
}

int main()
{
    int n;
    cin >> n;

    cout << fact(n) << endl;

    return 0;
}