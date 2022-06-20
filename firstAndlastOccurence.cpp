#include <iostream>
using namespace std;

// how to make lower_bound and upper_bound function: with little difference

int upperBound(int *arr, int n, int k)
{
    int s = 0;
    int e = n - 1;
    int ub;

    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (arr[mid] == k)
        {
            ub = mid;
            s = mid + 1;
        }
        else if (arr[mid] > k)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return ub;
}

int lowerBound(int *arr, int n, int k)
{
    int s = 0;
    int e = n - 1;
    int lb;

    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (arr[mid] == k)
        {
            lb = mid;
            e = mid - 1;
        }
        else if (arr[mid] > k)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return lb;
}

int main()
{

    int arr[] = {1, 2, 3, 4, 5, 6, 6, 6, 6, 6, 6, 6, 7, 8};
    int n = sizeof(arr) / sizeof(int);

    int k = 6;

    int first = lowerBound(arr, n, k);
    int last = upperBound(arr, n, k);
    cout << "First Occurence: " << first << endl;
    cout << "Last Occurence: " << last << endl;

    return 0;
}
