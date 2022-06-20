#include <iostream>
#include <climits>
using namespace std;

bool isPossible(int arr[100], int n, int m, int curmin)
{
    int student = 1;
    int pages = 0;
    for (int i = 0; i < n; i++)
    {
        if (pages + arr[i] > curmin)
        {
            pages = arr[i];
            student++;
            if (student > m)
            {
                return false;
            }
        }
        else
        {
            pages += arr[i];
        }
    }
    return true;
}

int findpages(int arr[100], int n, int m)
{
    if (n < m)
    {
        return -1;
    }

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    int s = arr[n - 1]; //
    int e = sum;
    int ans = INT_MAX;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (isPossible(arr, n, m, mid))
        {
            ans = min(mid, ans);
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;
    int extra[t];
    for (int x = 0; x < t; x++)
    {

        int m, n;
        cin >> n >> m;

        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        extra[x] = findpages(arr, n, m);
    }

    for (int i = 0; i < t; i++)
    {
        cout << extra[i] << endl;
    }

    return 0;
}
