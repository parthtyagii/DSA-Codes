#include <iostream>
using namespace std;

void subsequences(char *arr, char *output, int i, int j)
{
    if (arr[i] == '\0')
    {
        output[j] = '\0';
        cout << output << endl;
        return;
    }

    output[j] = arr[i];
    // including input character
    subsequences(arr, output, i + 1, j + 1);

    // excluding input character
    subsequences(arr, output, i + 1, j);
}

int main()
{
    char arr[50];
    cin >> arr;
    char output[100];

    subsequences(arr, output, 0, 0);

    return 0;
}