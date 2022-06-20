#include <iostream>
using namespace std;

// Count no. of Prime numbers between a and b:

void primeSieve(int arr[])
{
    arr[0] = arr[1] = 0;
    arr[2] = 1;

    //we want to check only odd numbers.
    for (int i = 3; i < 10000; i += 2)
    {
        arr[i] = 1;
    }

    // Applying Sieve method: (consider taking i and j as long long for very large array)
    for (int i = 3; i < 10000; i += 2)
    {
        // if current number is prime:
        if (arr[i] == 1)
        {
            // marking all multiples of i as not prime:
            for (int j = i * i; j < 10000; j += i)
            {
                arr[j] = 0;
            }
        }
    }
}

int main()
{
    int arr[10000] = {0};
    primeSieve(arr);

    int csum[10000]={0};      
    for (int i = 1; i < 10000; i++)
    {
        csum[i] = csum[i - 1] + arr[i];
    }

    int q;
    cin >> q;
    while (q > 0)
    {
        int a, b;
        cin >> a >> b;
        cout << (csum[b] - csum[a]) << endl;
        q--;
    }

    return 0;
}