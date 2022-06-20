#include <iostream>
#include <string>
#include <climits>
#include <algorithm>
using namespace std;

// by doing partitioning: how many transfers do we have to make to balance each partition...

int main()
{
    int t;
    cin >> t;
    int arr[100000];

    while (t--)
    {
        int n, max_load = INT_MIN, load = 0;
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            load += arr[i];
        }

        if (load % n != 0)
        {
            cout << "-1" << endl;
            continue;
        }

        load = load / n;

        int diff = 0;
        for (int i = 0; i < n; i++)
        {
            diff += (arr[i] - load);
            int ans = max(diff, -diff);
            max_load = max(max_load, ans);
        }

        cout << max_load << endl;
    }

    return 0;
}