#include <iostream>
using namespace std;

// Reading sentences and paragraph: 'cin' won't work.

void readline(char a[], int maxl, char alpha = '\n')
{
    int i = 0;
    char ch = cin.get();
    while (ch != alpha)
    {
        a[i] = ch;
        i++;
        if (i == (maxl - 1))
        {
            break;
        }
        ch = cin.get();
    }
    if (i == (maxl - 1))
    {
        a[i] = '\0';
    }
}

int main()
{
    char arr[1000];
    // Function to read sentences and paragraph.

    // readline(arr, 1000);
    // cout << arr;

    // We can alo use inbuilt function.
    cin.getline(arr, 1000, '@');
    cout << arr;

    return 0;
}
