#include <iostream>
using namespace std;

// templates: algorithm level
// syntax: template<class t> or template<typename t>

template <class t>
int search(t arr[], int n, t k)
{

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == k)
        {
            return i;
        }
    }
 
    return n;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = 7;
    int k = 5;

    // cout << search(arr, n, k) << endl;

    char arr1[] = "parth tyagi";
    cout << search(arr1, 11, 'y') << endl;

    return 0;
}