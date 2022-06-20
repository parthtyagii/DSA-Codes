#include <iostream>
#include <algorithm>
using namespace std;

int main()
{

    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n1 = sizeof(arr1) / sizeof(int);

    // Rotate: will rotate about middle parameter.
    rotate(arr1, arr1 + 4, arr1 + n1);
    for (int x : arr1) // for each loop c++ 11.
    {
        cout << x << " ";
    }
    cout << endl;

    // Next Permutation: next arrangement just bigger than current array.
    int arr2[] = {4,3,2,1};
    int n2 = sizeof(arr2) / sizeof(int);
    next_permutation(arr2, arr2 + n2);
    next_permutation(arr2, arr2 + n2);
    next_permutation(arr2, arr2 + n2);
    next_permutation(arr2, arr2 + n2);
    next_permutation(arr2, arr2 + n2);
    next_permutation(arr2, arr2 + n2);

    for (int x : arr2)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
