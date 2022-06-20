#include <iostream>
#include<climits>
using namespace std;

// Maximum sum of a sub array: Kadane's Algorithm

int main()
{
    int n;
    cout << "Numbers of elements: ";
    cin >> n;
    int array[100];
    cout << "Enter the values in array:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }

    int csum = 0;
    // int msum = INT_MIN;
    int msum=0;
    // Kadane's algorithm: Using only one iteration or loop.
    for (int i = 0; i < n; i++)
    {
        csum = csum + array[i];

        if (csum > msum)
        {
            msum = csum;
        }
        if (csum < 0)
        {
            csum = 0;
        }
    }

    cout << "Maximum sum of a sub-array: " << msum;

    return 0;
}
