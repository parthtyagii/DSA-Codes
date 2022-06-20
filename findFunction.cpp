#include <iostream>
#include <algorithm>
using namespace std;

// Find function: work like linear search

int main()
{

    int arr[] = {12, 32, 44, 44, 44, 35, 67, 34, 91};
    int n = sizeof(arr) / sizeof(int);

    int k;
    cin >> k;
    // int* ptr= find(arr, arr+n, k);
    auto ptr = find(arr, arr + n, k); // find returns address.
    int indx = ptr - arr;
    if (indx == n)
    {
        cout << k << " not present" << endl;
    }
    else
    {
        cout << k << " is at index " << indx << endl;
    }

    return 0;
}
