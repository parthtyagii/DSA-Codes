#include <iostream>
#include <unordered_set>
using namespace std;

// Longest consecutive sub-sequence: using unordered_set...

int largestSub(int *arr, int n)
{

    unordered_set<int> s; // unordered_set uses hashtable...(O(1) complexity)
    int lar_streak = 1;

    for (int i = 0; i < n; i++)
    {
        s.insert(arr[i]);
    }

    for (int i = 0; i < n; i++)
    {
        int no = arr[i];

        if (s.find(no - 1) == s.end())
        {
            int streak = 1;
            no = no + 1;
            while (s.find(no) != s.end())
            {
                no = no + 1;
                streak++;
            }
            lar_streak = max(lar_streak, streak);
        }
    }

    return lar_streak;
}

int main()
{
    int arr[] = {14, 5, 1, 2, 6, 3, 7, 8, 9, 13, 15, 11, 12, 13, 17};
    int n = sizeof(arr) / sizeof(int);

    cout << largestSub(arr, n) << endl;

    return 0;
}