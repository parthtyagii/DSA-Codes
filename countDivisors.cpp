#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> primeSieve(int arr[])
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

    vector<int> v;
    for (int i = 0; i < 1000; i++)
    {
        if (arr[i] == 1)
        {
            v.push_back(i);
        }
    }
    return v;
}

vector<pair<int, long>> countDivisors(int n, vector<int> &v)
{
    int i = 0;
    int p = v[i];
    int ans = 1;
    long sum = 1;
    while (p * p <= n)
    {
        int count = 0;
        if (n % p == 0)
        {
            while (n % p == 0)
            {
                n = n / p;
                count++;
            }
            ans = ans * (count + 1);
            long b = pow(p, count);
            long a = p * (b - 1);
            sum = sum * (1 + (a / (p - 1)));
        }
        i++;
        p = v[i];
    }

    if (n != 1)
    {
        ans = ans * 2;
        sum = sum * (n + 1);
    }

    vector<pair<int, long>> x;
    x.push_back(make_pair(ans, sum));

    return x;
}

int main()
{
    int arr[1000] = {0};
    vector<int> v = primeSieve(arr);

    int n;
    cin >> n;
    vector<pair<int, long>> divisocs = countDivisors(n, v);

    cout << "Number of divisors: " << divisocs[0].first << endl
         << "Sum of divisors: " << divisocs[0].second << endl;

    return 0;
}