#include <iostream>
#include <vector>
using namespace std;

vector<int> primeSieve(int *arr)
{
    arr[0] = arr[1] = 0;
    arr[2] = 1;
    for (int i = 3; i < 1000; i += 2)
    {
        arr[i] = 1;
    }

    for (int i = 3; i < 1000; i++)
    {
        if (arr[i] == 1)
        {
            for (int j = i * i; j < 1000; j += i)
            {
                arr[j] = 0;
            }
        }
    }

    vector<int> v;
    for (int i = 2; i < 1000; i++)
    {
        if (arr[i] == 1)
        {
            v.push_back(i);
        }
    }
    return v;
}

vector<pair<int, int>> primeFactors(vector<int> &v, int q)
{
    vector<pair<int, int>> alpha;
    int i = 0;
    int p = v[i];

    while ((p * p) <= q)
    {
        int count = 0;
        if (q % p == 0)
        {
            while ((q % p) == 0)
            {
                q = q / p;
                count++;
            }
            alpha.push_back(make_pair(p, count));
        }
        i++;
        p = v[i];
    }

    if (q != 1)
    {
        alpha.push_back(make_pair(q, 1));
    }

    return alpha;
}

int main()
{
    int arr[1000] = {0};
    vector<int> v = primeSieve(arr);

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        int q;
        cin >> q;
        vector<pair<int, int>> factors = primeFactors(v, q);

        for (auto x : factors)
        {
            cout << x.first << "^" << x.second << endl;
        }
    }

    return 0;
}