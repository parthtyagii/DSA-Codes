#include <iostream>
#include <cstring>
using namespace std;

void filter(int i, char arr[])
{
    int j = 0;
    while (i > 0)
    {
        int lastBit = (i & 1);
        if (lastBit == 1)
        {
            cout << arr[j];
        }
        j++;
        i = (i >> 1);
    }
    cout << endl;
}

void printSubsets(char arr[])
{
    int N = strlen(arr);
    for (int i = 0; i < (1 << N); i++) // (1<<N) == 2^N
    {
        filter(i, arr);
    }
}

int main()
{
    char arr[100];
    cin >> arr;
    printSubsets(arr);

    return 0;
}
