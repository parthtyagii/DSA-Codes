#include <iostream>
using namespace std;

// Aggressive Cows Problem: spoj.com

bool canPlace(int *arr, int n, int c, int min_sep)
{
    // place the first cow in first stall.
    int lastcow = arr[0];
    int count = 1; // number of cows been placed.
    for (int i = 1; i < n; i++)
    {
        if ((arr[i] - lastcow) >= min_sep)
        {
            lastcow = arr[i];
            count++;
            if (count == c)
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{

    int arr[] = {1, 2, 4, 8, 9}; // sorted array but we are not applying binary search on this array.
    int n = 5;

    int cows = 3;

    // search Space:
    int s = 0;
    int e = arr[n - 1] - arr[0];
    int ans = 0;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        bool rakhPaye = canPlace(arr, n, cows, mid);
        if (rakhPaye)
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }

    cout << ans << endl;

    return 0;
}
