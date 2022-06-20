#include <iostream>
#include <algorithm>
using namespace std;

// Binary Search function: returns bool value.
//          --> array must be sorted.
int main()
{

    int arr[] = {10, 20, 70, 60, 40, 20, 50, 50, 50, 50, 60, 30};
    int n = sizeof(arr) / sizeof(int);

    int k;
    cin >> k;

    sort(arr, arr + n);
    auto ptr = binary_search(arr, arr + n, k);
    if (ptr)
    {
        cout << "Present!" << endl;
    }
    else
    {
        cout << "Absent!" << endl;
    }

    // lower bound: address of first element >= k.
    auto lb = lower_bound(arr, arr + n, k);
    int L = lb - arr;
    cout << "lower bound: " << L << endl;

    // Upper bound: address of first element > k.
    auto up = upper_bound(arr, arr + n, k);
    int U = up - arr;
    cout << "upper bound: " << U << endl;

    // frequency of k:
    int freq = U - L;
    cout << "frequency of k: " << freq << endl;

    return 0;
}
