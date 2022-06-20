#include <iostream>
using namespace std;

// All Prime numbers between 1 and N:

void primeSieve(int arr[])
{
    arr[0] = arr[1] = 0;
    arr[2] = 1;

    //we want to check only odd numbers.
    for (int i = 3; i < 1000; i += 2)
    {
        arr[i] = 1;
    }

    // Applying Sieve method: (consider taking i and j as long long for very large array)
    for (int i = 3; i < 1000; i += 2)
    {
        // if current number is prime:
        if (arr[i] == 1)
        {
            // marking all multiples of i as not prime:
            for (int j = i * i; j < 1000; j += i)
            {
                arr[j] = 0;
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;

    int arr[1000] = {0};
    primeSieve(arr);

    for (int i = 2; i <= n; i++)
    {
        if (arr[i] == 1)
        {
            cout << i << " ";
        }
    }

    return 0;
}