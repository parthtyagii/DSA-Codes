#include <iostream>
#include <unordered_set>
#include <unordered_map>
using namespace std;

// Finding largest sub array with zero sum:

int sumZero(int *arr, int n)
{
    unordered_map<int, int> m;
    int preSum = 0;
    int len = 0;

    for (int i = 0; i < n; i++)
    {
        preSum += arr[i];

        if (preSum == 0)
        {
            len = max(len, i + 1);
        }

        if (m.find(preSum) != m.end())
        {
            len = max(len, i - m[preSum]);
        }
        else
        {
            m[preSum] = i;
        }
    }

    return len;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << sumZero(arr, n) << endl;

    return 0;
}