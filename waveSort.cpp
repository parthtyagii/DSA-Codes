#include <iostream>
using namespace std;

void wave(int *arr, int n)
{
    for (int i = 0; i < n; i += 2)
    {
        if (i != 0 and arr[i] < arr[i - 1])
        {
            swap(arr[i], arr[i - 1]);
        }
        if (i != n - 1 and arr[i] < arr[i + 1])
        {
            swap(arr[i], arr[i + 1]);
        }
    }
    return;
}

int main()
{
    int arr[] = {2, 3, 6, 1, 5, 9, 7, 13, 27};
    int n = sizeof(arr) / sizeof(int);

    wave(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}