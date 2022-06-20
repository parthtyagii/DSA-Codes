#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
using namespace std;

// Longest consecutive sub-sequence: using hashmap...

int largestSub(int *arr, int n)
{
    unordered_map<int, int> m;

    for (int i = 0; i < n; i++)
    {

        int no = arr[i];

        if (m.count(no - 1) == 0 and m.count(no + 1) == 0)
        {
            m[no] = 1;
        }
        else if (m.count(no - 1) and m.count(no + 1))
        {
            int l1 = m[no - 1];
            int l2 = m[no + 1];

            int streak = l1 + l2 + 1;
            m[no - l1] = streak;
            m[no + l2] = streak;
        }
        else if (m.count(no - 1) and !m.count(no + 1))
        {
            int len = m[no - 1];
            m[no - len] = len + 1;
            m[no] = len + 1;
        }
        else
        {
            int len = m[no + 1];
            m[no + len] = len + 1;
            m[no] = len + 1;
        }
    }

    int largest = 0;
    for (auto x : m)
    {
        largest = max(largest, x.second);
    }

    return largest;
}

int main()
{
    int arr[] = {14, 5, 1, 2, 6, 3, 7, 8, 9, 13, 15, 11, 12, 13, 17};
    int n = sizeof(arr) / sizeof(int);

    cout << largestSub(arr, n) << endl;

    return 0;
}