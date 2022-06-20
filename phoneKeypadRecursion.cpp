#include <iostream>
using namespace std;

char keypad[][15] = {"", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};

void generateStrings(char *arr, char *output, int i, int j)
{
    if (arr[i] == '\0')
    {
        output[j] = '\0';
        cout << output << endl;
        return;
    }

    int num = arr[i] - '0';
    if (num == 0 || num == 1)
    {
        generateStrings(arr, output, i + 1, j);
    }
    for (int x = 0; keypad[num][x] != '\0'; x++)
    {
        output[j] = keypad[num][x];
        generateStrings(arr, output, i + 1, j + 1);
    }
    return;
}

int main()
{
    char arr[10];
    cin >> arr;
    char output[1000];

    generateStrings(arr, output, 0, 0);

    return 0;
}