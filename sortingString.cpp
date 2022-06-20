#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// String Sorting:

bool comparator(string s1, string s2)
{
    if (s1.length() == s2.length())
    {
        return s1 < s2;
    }

    return s1.length() > s2.length();
}

int main()
{
    int n;
    cin >> n;
    cout << "Enter the Strings:" << endl;
    cin.get();
    string s[100];
    for (int i = 0; i < n; i++) 
    {
        getline(cin, s[i]);
    }

    sort(s, s + n, comparator);

    cout << "Sorted Strings:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << s[i] << endl;
    }

    return 0;
}
