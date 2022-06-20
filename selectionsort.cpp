#include <iostream>
using namespace std;

// Selection Sort: An algorithm to sort randomly shuffled array.

void selectionsort(int array[], int n)
{
    // starting the loop for unsorted loop:
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i; j < n; j++)
        {
            if (array[j] < array[min])
            {
                min = j;
            }
        }
        // swapping the minimum with 'i' position value:
        swap(array[i], array[min]);
    }
}

int main()
{
    int n;
    cout << "Number of elements in array: ";
    cin >> n;

    int array[100];
    cout << "Enter values in array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }

    selectionsort(array, n);

    cout << "Your sorted aaray: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }

    return 0;
}
