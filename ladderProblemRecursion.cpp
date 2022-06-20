#include <iostream>
using namespace std;

long long ladders(long long n)
{
    if (n == 0)
    {
        return 1;
    }
    if (n < 0)
    {
        return 0;
    }

    // here we know that we want to calculate for 1,2 and 3.
    // otherwise we can put a loop upto k and add the answer to 'ans'.
    long long ans = ladders(n - 1) + ladders(n - 2) + ladders(n - 3);

    return ans;    
}

int main()
{
    long long n;
    cin >> n;

    cout << ladders(n) << endl;

    return 0;
}