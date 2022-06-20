#include <iostream>
using namespace std;

int main()
{
    int sum[64] = {0};
    int n, no;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> no;
        int j = 0;
        while (no > 0)
        {
            sum[j] += (no & 1);
            j++;
            no = (no >> 1);
        }
    }

    int ans = 0;
    int p = 1;
    for (int i = 0; i < 64; i++)
    {
        sum[i] = (sum[i] % 3);
        ans += (sum[i] * p);
        p = (p << 1);
    }

    cout << ans << endl;

    return 0;
}
