#include <iostream>
#include <climits>
using namespace std;

// Largest and Smallest number in an Array:

int main()
{
    int a;
    cout << "Number of elements: ";
    cin >> a;

    int array[100];
    for (int i = 0; i < a; i++)
    {
        cin >> array[i];
    }

    // Now,
    int largest = INT_MIN;
    int smallest = INT_MAX;

    // First method:

    // for (int i = 0; i < a; i++)
    // {
    //     if (largest < array[i])
    //     {
    //         largest = array[i];
    //     }

    //     if (smallest > array[i])
    //     {
    //         smallest = array[i];
    //     }
    // }

    // Second method:

    for (int i = 0; i < a; i++)
    {
        largest = max(largest, array[i]);
        smallest = min(smallest, array[i]);
    }

    cout << "largest number: " << largest << endl;
    cout << "smallest number: " << smallest << endl;

    return 0;
}