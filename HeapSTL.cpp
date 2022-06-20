#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Heap or Priority  Queue STL:

int main()
{
    priority_queue<int> q;                             // By default maxHeap....
    priority_queue<int, vector<int>, greater<int>> q1; // minHeap...we have to pass two parameters.
    int n;
    cin >> n;
    while (n > 0)
    {
        int d;
        cin >> d;
        q1.push(d); // O(logN)...
        n--;
    }

    while (!q1.empty())
    {
        cout << q1.top() << " "; // O(1)...
        q1.pop();                // O(logN)...
    }

    return 0;
}