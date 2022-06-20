#include <iostream>
#include <unordered_set>
using namespace std;

// Finding sub array with zero sum:

bool Check(int *arr, int n)
{
    unordered_set<int> s;
    int preSum = 0;

    for (int i = 0; i < n; i++)
    {
        preSum += arr[i];

        if (preSum == 0 or s.find(preSum) != s.end())
        {
            return true;
        }

        s.insert(preSum);
    }

    return false;
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

    if (Check(arr, n))
    {
        cout << "Sub-array with sum zero is present." << endl;
    }
    else
    {
        cout << "Sub-array with sum zero is not present." << endl;
    }

    return 0;
}