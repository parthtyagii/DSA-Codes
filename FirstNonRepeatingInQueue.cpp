#include <iostream>
#include <queue>
using namespace std;

// First non-repeating character in the queue.

int main()
{
    queue<char> q;
    int freq[27] = {0};

    char ch;
    cin >> ch;

    while (ch != '.')
    {
        // logic:
        // push element into queue and change int frequency.
        q.push(ch);
        freq[ch - 'a']++;

        while (!q.empty())
        {
            // query:
            int idx = q.front() - 'a';
            // checking if current front has frequency 1 or not.
            if (freq[idx] > 1)
            {
                q.pop();
            }
            else
            {
                cout << q.front() << endl;
                break;
            }
        }

        // if q is empty...print -1.
        if (q.empty())
        {
            cout << "-1" << endl;
        }

        cin >> ch;
    }

    return 0;
}