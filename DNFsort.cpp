#include <iostream>
using namespace std;

void DNF(int *arr, int n)
{
    int low = 0;
    int i = 0;
    int j = n - 1;
    while (i < j)
    {
        if (arr[i] == 0)
        {
            swap(arr[i], arr[low]);
            low++;
            i++;
        }
        if (arr[i] == 1)
        {
            i++;
        }
        if (arr[i] == 2)
        {
            swap(arr[i], arr[j]);
            j--;
        }
    }
}

int main()
{
    int arr[] = {2, 0, 0, 2, 1, 2, 1, 0, 2, 0, 0, 1};
    int n = sizeof(arr) / sizeof(int);

    DNF(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}