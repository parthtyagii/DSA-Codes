#include <iostream>
#include <string>
#include <set>
using namespace std;

void permutations(char *arr, int i, set<string> &s)
{
    // Base case:
    if (arr[i] == '\0')
    {
        string t(arr);
        s.insert(t);

        return;
    }

    for (int j = i; arr[j] != '\0'; j++)
    {
        swap(arr[i], arr[j]);
        permutations(arr, i + 1, s);
        // Backtracking: To restore original array.
        swap(arr[i], arr[j]);
    }
}

int main()
{
    char arr[100];
    cin >> arr;

    cout << "All unique permutaions of " << arr << ":" << endl;

    set<string> s;
    permutations(arr, 0, s);

    for (auto x : s)
    {
        cout << x << endl;
    }

    return 0;
}
