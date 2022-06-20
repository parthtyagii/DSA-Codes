#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

bool isPossible(long long *arr, long long n, long long k, long long mid, long long t)
{
    long long time = 0;
    long long painter = 1;
    for (int i = 0; i < n; i++)
    {
        if ((time + (arr[i] * t)) > mid)
        {
            painter++;
            time = arr[i] * t;
            if (painter > k)
            {
                return false;
            }
        }
        else
        {
            time += arr[i] * t;
        }
    }
    return true;
}

int main()
{
    unsigned long long n, k, t;
    cin >> n >> k >> t;

    long long arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    long long sum = 0;
    long long s = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        s = max(s, arr[i]);
    }

    s = s * t;
    long long e = sum * t;
    long long ans = 0;
    while (s <= e)
    {
        long long mid = (s + e) / 2;
        if (isPossible(arr, n, k, mid, t))
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }

    cout << (ans % 10000003) << endl;

    return 0;
}
