#include <iostream>
#include <algorithm> // Header file to use sorting function.
using namespace std;

// Inbuilt Sort in C++ STL: Much more efficient than basic sorting algorithm.

bool compare(int a, int b){
    return a<b;
}

int main()
{
    int n;
    cout << "Number of elements: ";
    cin >> n;
    int array[100];
    cout << "Enter values in array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    // We can also pass a function if we want the answer to be in decending order.
    sort(array, array + n, compare);

    cout << "Your sorted array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }

    return 0;
}
