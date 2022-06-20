#include <iostream>
#include <cstring>
using namespace std;

int stringToint(char *arr, int n)
{
    if (n == 0)
    {
        return 0;
    }
    int digit = arr[n - 1] - '0';
    int x = stringToint(arr, n - 1);

    return ((x * 10) + digit);
}

int main()
{
    char arr[] = "2048";
    int len = strlen(arr);

    cout << stringToint(arr, len) << endl;
    cout << stringToint(arr, len) + 2 << endl;

    return 0;
}