#include <iostream>
using namespace std;

// Using Recursion: for binary search

void findNum(int *arr, int first, int last, int k)
{
    if (first > last)
    {
        cout << "not found" << endl;
        return; // why do i have to write a return statement here??
                // Can you explain whats happens if i do not put a return statement here. its not working without return.
    }
    int mid = (first + last) / 2;
    if (arr[mid] > k)
    {
        findNum(arr, first, mid - 1, k);
    }
    else if (arr[mid] < k)
    {
        findNum(arr, mid + 1, last, k);
    }
    else
    {
        cout << mid << endl; // Also do i need a return statement here??
        return;
    }
}

int main()
{
    int k;
    cin >> k;
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 9};
    int n = sizeof(arr) / sizeof(int);
    int last = n - 1;
    int first = 0;

    findNum(arr, first, last, k);

    return 0;
}