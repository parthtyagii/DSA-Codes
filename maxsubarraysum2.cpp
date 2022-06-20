#include <iostream>
using namespace std;

// Max sum of a subarray: using concept of comulative sum.
//                  ----> This process is known as 'Precomputing'.

int main()
{
    int n;
    cout << "Number of elements: ";
    cin >> n;
    int array[100];
    int comulative[100];

    cout << "Enter the values: " << endl;
    // cin>>array[0];
    // comulative[0] = array[0];
    comulative[-1] = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
        comulative[i] = comulative[i - 1] + array[i];
    }
    long int csum = 0;
    long int msum = 0;
    int left, right;

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            csum = 0;

            // Using the concept of comultaive sum instead of loop.
            csum = comulative[j] - comulative[i - 1];

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
