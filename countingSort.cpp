#include <iostream>
#include <climits>
using namespace std;

// Counting Sort: not for very large range(>10^7)...

void countSort(int *arr, int n)
{
    // Find out the largest number in the array:
    int largest = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        largest = max(largest, arr[i]);
    }

    // creating frequency array:
    int freq[largest + 1] = {0};
    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }

    int j = 0;
    for (int i = 0; i <= largest; i++)
    {
        while (freq[i] > 0)
        {
            arr[j] = i;
            freq[i]--;
            j++;
        }
    }
}

int main()
{
    int arr[] = {6, 4, 78, 34, 22, 92, 2, 1, 4, 6, 44, 4, 5, 7, 8, 10};
    int n = sizeof(arr) / sizeof(int);

    countSort(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl
         << "Counting Sort implemented successfully !!!!" << endl;

    return 0;
}