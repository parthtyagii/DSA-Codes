#include <iostream>
using namespace std;

// Two pointers approach: pair sum problem.
//               ---> Array must be sorted.

int main()
{
    // Given array MUST be SORTED.
    int array[] = {1, 2, 4, 5, 8, 10, 13, 15, 19};
    int k;
    cout << "Enter the number: ";
    cin >> k;
    int csum = 0;

    int i = 0;
    int j = (sizeof(array) / sizeof(int)) - 1;

    cout << "Pairs are: " << endl;
    while (i < j)
    {
        csum = 0;
        csum = array[i] + array[j];
        if (csum > k)
        {
            j--;
        }
        else if (csum < k)
        {
            i++;
        }
        else if (csum == k)
        {
            cout << array[i] << " and " << array[j] << endl;
            i++;
            j--;
        }
    }
    if (i >= j)
    {
        cout << "No pair exist further." << endl;
    }

    return 0;
}
