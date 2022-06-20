#include <iostream>
#include <unordered_set>
#include <unordered_map>
using namespace std;

// Finding largest sub array with k sum:

int sumZero(int *arr, int n, int k)
{
    unordered_map<int, int> m;
    int preSum = 0;
    int len = 0;

    for (int i = 0; i < n; i++)
    {
        preSum += arr[i];

        if (preSum == k)
        {
            len = max(len, i + 1);
        }

        if (m.find(preSum - k) != m.end())
        {
            len = max(len, i - m[preSum - k]);
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

    int key;
    cin >> key;

    cout << sumZero(arr, n, key) << endl;

    return 0;
}