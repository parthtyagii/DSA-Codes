#include <iostream>
#include <cstring>
using namespace std;

// Palindromic String: checking

bool palindromic(char arr[100])
{
    int i = 0;
    int j = strlen(arr) - 1;
    while (i < j)
    {
        if (arr[i] == arr[j])
        {
            i++;
            j--;
        }
        else
        {
            return false;
        }
    }
    return true;
}

int main()
{

    char arr[100];
    // cin >> arr;
    cin.getline(arr, 100);
    cout << "Your string is: " << endl;
    // cout<<arr<<endl;

    bool ch = palindromic(arr);
    if (ch)
    {
        cout << "Palimdromic String" << endl;
    }
    else
    {
        cout << "Not Palindromic" << endl;
    }

    return 0;
}
