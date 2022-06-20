#include <iostream>
using namespace std;

int binarysearch(int q[], int n, int a)
{
    int s = 0;
    int e = n - 1;

    while (e >= s)
    {
        int mid = (s + e) / 2;

        if (q[mid] == a)
        {
            return mid;
        }
        else if (mid > a)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }

    return -1;
}

int main()
{

    int n;
    cout << "Number of inputs: ";
    cin >> n;

    int array[100];
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }

    int a;
    cout << "Enter the number you want to search: ";
    cin >> a;

    cout << "Your entered number is present at index(-1 = number is not present): " << binarysearch(array, n, a);

    return 0;
}
