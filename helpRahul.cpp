#include <iostream>
using namespace std;
int helping(int *arr, int n, int k)
{
    int s = 0;
    int e = n - 1;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (arr[mid] == k)
        {
            return mid;
        }
        else if (arr[mid] >= arr[s])
        {
            if (k <= arr[mid] and k >= arr[s])
            {
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }
        else if (arr[mid] <= arr[e])
        {
            if (k >= arr[mid] and k <= arr[e])
            {
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }
    }
    return -1;
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

    int k;
    cin >> k;

    int ans = helping(arr, n, k);
    cout << ans << endl;

    return 0;
}
