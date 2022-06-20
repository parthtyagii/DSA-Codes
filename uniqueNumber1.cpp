#include <iostream>
using namespace std;

// Unique Number-1: solving problem using "^" operator.

int main()
{
    int n;
    cin >> n;

    int num;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        ans = ans ^ num;
    }

    cout << ans << endl;

    return 0;
}