#include <iostream>
using namespace std;

// Comparators: how to pass a function as parameter and how it works,
//        ----> with the help of bubble sort.

bool compare(int a, int b)
{
    return a < b;
}

void bubblesort(int array[], int n, bool (&com)(int a, int b))
{
    for (int itr = 1; itr < n; itr++)
    {
        for (int i = 0; i <= (n - itr - 1); i++)
        {
            // 'if' statement will work if function return true(1) value.
            if (com(array[i], array[i + 1]))
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

    // here we are not calling function (compare) but passing it as an argument.
    bubblesort(array, n, compare);

    cout << "Your sorted array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }

    return 0;
}
