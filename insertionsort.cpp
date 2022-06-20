#include <iostream>
using namespace std;

// Insertion Sort: Inserting current element at right place.

void insertionsort(int array[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int q = array[i];
        int w = i - 1;
        while (w >= 0 and array[w] > q)
        {
            array[w+1] = array[w];
            w--;
        }
        array[w + 1] = q;
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

    insertionsort(array, n);

    cout << "Your sorted array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << array[i]<<" ";
    }

    return 0;
}
