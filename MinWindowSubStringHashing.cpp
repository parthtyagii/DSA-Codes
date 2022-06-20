#include <iostream>
#include <string>
#include <climits>
using namespace std;

// Minimum window sub-string: using sliding window concept...

string find_window(string s, string p)
{
    int SL = s.length();
    int PL = p.length();

    if (PL > SL)
    {
        return "No String!!";
    }

    char FS[256] = {0};
    char FP[256] = {0};
    int start = 0;
    int min_len = INT_MAX;
    int start_idx = -1;

    for (int i = 0; i < PL; i++)
    {
        char ch = p[i];
        FP[ch]++;
    }

    int count = 0;
    for (int i = 0; i < SL; i++)
    {
        char ch = s[i];
        FS[ch]++;

        if (FP[ch] != 0 and FS[ch] <= FP[ch])
        {
            count++;
        }

        if (count == PL)
        {
            char temp = s[start];

            while (FP[temp] == 0 or FS[temp] > FP[temp])
            {
                FS[temp]--;
                start++;
                temp = s[start];
            }

            int window_len = i - start + 1;
            if (window_len < min_len)
            {
                min_len = window_len;
                start_idx = start;
            }
        }
    }

    if (start_idx == -1)
    {
        return "No String!!";
    }
    string ans = s.substr(start_idx, min_len);
    return ans;
}

int main()
{
    string s = "hllloeaeo world";
    string p = "eelo";

    cout << find_window(s, p) << endl;

    return 0;
}
