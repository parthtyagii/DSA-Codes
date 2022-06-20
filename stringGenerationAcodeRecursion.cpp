#include <iostream>
using namespace std;

void generateStrings(char *arr, char *output, int i, int j)
{
    if (arr[i] == '\0')
    {
        output[j] == '\0';
        cout << output << endl;
        return;
    }

    if (arr[i] == '0')
    {
        generateStrings(arr, output, i + 1, j);
    }
    else
    {
        // for sigle characters
        int num = arr[i] - '0';
        char ch1 = num - 1 + 'A';
        output[j] = ch1;
        generateStrings(arr, output, i + 1, j + 1);

        // for double characters
        if (arr[i + 1] != '\0')
        {
            int unit = arr[i + 1] - '0';
            int digit = (num * 10) + unit;
            int ch2 = digit - 1 + 'A';
            if (digit <= 26)
            {
                output[j] = ch2;
                generateStrings(arr, output, i + 2, j + 1);
            }
        }
    }
}

int main()
{
    char arr[100];
    cin >> arr;
    char output[1000];

    generateStrings(arr, output, 0, 0);

    return 0;
}