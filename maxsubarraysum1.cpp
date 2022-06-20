#include <iostream>
using namespace std;

// Maximum sum of a Subarray: also print the subrarray.

int main()
{
    int n;
    cout << "Number of elements: ";
    cin >> n;
    int array[100];
    cout << "Enter the values: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    int csum = 0;
    int msum = 0;
    int left, right;

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            csum = 0;
            for (int k = i; k <= j; k++)
            {
                csum = csum + array[k];
            }
            if (msum < csum)
            {
                msum = csum;
                left = i;
                right = j;
            }
        }
    }
    cout << "Sub-array with maximum sum: " << endl;
    for (int q = left; q <= right; q++)
    {
        cout << array[q] << " ";
    }
    cout << endl;
    cout << "Maximum sum of a subarray: " << msum << endl;

    return 0;
}
