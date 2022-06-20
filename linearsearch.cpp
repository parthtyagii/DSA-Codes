#include <iostream>
using namespace std;

// Linear Search: An algorithm to find a particular element in an array.

int main()
{

    int n;
    cout << "Number of elements in array: ";
    cin >> n;

    int array[100];
    cout << "Enter the elements:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }

    int a;
    cout << "Enter the number you want to check: ";
    cin >> a;

    int i;
    for (i = 0; i <= n - 1; i++)
    {
        if (array[i] == a)
        {
            cout << "Your number " << a << " is present at index " << i << ".";
            break;
        }
    }

    if (i == n)
    {
        cout << "Your number is not present in the array.";
    }

    return 0;
}
