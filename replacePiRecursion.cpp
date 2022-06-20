#include <iostream>
using namespace std;

//recursion:

void replacePi(char *arr, int i)
{
    if (arr[i] == '\0' or arr[i + 1] == '\0')
    {
        return;
    }

    if (arr[i] == 'P' and arr[i + 1] == 'i')
    {
        int j = i + 2;
        while (arr[j] != '\0')
        {
            j++;
        }
        while (j >= (i + 2))
        {
            arr[j + 2] = arr[j];
            j--;
        }

        arr[i] = '3';
        arr[i + 1] = '.';
        arr[i + 2] = '1';
        arr[i + 3] = '4';
        replacePi(arr, i + 4);
    }
    else
    {
        replacePi(arr, i + 1);
    }
}

int main()
{
    char arr[100] = {'x', 'y', 'P', 'i', 'm', 'n', 'o','\0'};
    replacePi(arr, 0);

    for (auto x : arr)
    {
        cout << x;
    }

    return 0;
}