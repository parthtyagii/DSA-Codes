#include <iostream>
using namespace std;

void permutations(char *arr, int i, int &count)
{
    // Base case:
    if (arr[i] == '\0')
    {
        cout << arr << endl;
        count++;
        return;
    }

    for (int j = i; arr[j] != '\0'; j++)
    {
        swap(arr[i], arr[j]);
        permutations(arr, i + 1, count);
        // Backtracking: To restore original array. ----> Becoz we are not using extra space.
        swap(arr[i], arr[j]);
    }
}

int main()
{
    char arr[100];  
    cin >> arr;

    cout << "All permutaions of " << arr << ":" << endl;

    int count = 0;
    permutations(arr, 0, count);
    cout << "Total permutaions: " << count << endl;

    return 0;
}
