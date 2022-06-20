#include <iostream>
#include <cstring>
using namespace std;

// Remove Consecutive Duplicates in String: idea is to skip duplicate characters.

void removeDuplicates(char arr[100])
{
    int prev = 0;
    int l = strlen(arr); 
    for (int curr = 0; curr < l; curr++)
    {
        if (arr[prev] != arr[curr])
        {
            prev++;
            arr[prev] = arr[curr];
        }
    }

    arr[prev + 1] = '\0';
}

int main()
{

    char arr[100];
    cin.getline(arr, 100);
    cout << "Your new String: " << endl;

    removeDuplicates(arr);
    cout << arr << endl;

    return 0;
}
