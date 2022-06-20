#include <iostream>
using namespace std;

// Bubble Sort: Take the largest element to the end.

void bubblesort(int array[], int n)
{
    // Number of iterations for 'n' elements is n-1:
    for (int itr = 1; itr < n; itr++)
    {
        for (int i = 0; i <= (n - itr - 1); i++)
        {

            // Pair-wise swapping in unsorted array:
            if (array[i] > array[i + 1])
            {
                swap(array[i], array[i + 1]);
            }
        }
    }
}

int main()
{
    int n;
    cout << "Number of elements: ";
    cin >> n;

    int array[100];
    cout << "Enter the values in array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }

    bubblesort(array, n);

    cout << "Your sorted array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }

    return 0;
}
