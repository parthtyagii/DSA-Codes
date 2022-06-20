#include <iostream>
using namespace std;

// Generating Subarrays: How to print all sub arrays.

int main()
{
    int n;
    cout << "Number of elements: ";
    cin >> n;

    int array[1000];
    cout << "Enter the values in array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }

    cout << "Printing all the sub-arrays: " << endl;

    // Selecting starting index of first subarray.
    for (int i = 0; i < n; i++)
    {
        // 'j' must be greater than or equal to 'i'.
        for (int j = i; j < n; j++)
        {
            for (int k = i; k <= j; k++)
            {
                cout << array[k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}
