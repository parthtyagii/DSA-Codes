#include <iostream>
#include <string>
#include <vector>
using namespace std;

class student
{
public:
    int marks;
    string name;
};

void bucketSort(student *s, int n)
{
    // assuming marks are in range 0-100:
    vector<student> v[101];

    // O(N) time:
    for (int i = 0; i < n; i++)
    {
        int m = s[i].marks;
        v[m].push_back(s[i]); 
    }

    cout << endl
         << "Sorting: " << endl;
    // iterating over vector: either way
    for (int i = 100; i >= 0; i--)
    {
        for (auto x : v[i])
        {
            cout << x.name << " " << x.marks << endl;
        }
    }

    // for (int i = 100; i >= 0; i--)
    // {
    //     for (vector<student>::iterator it = v[i].begin(); it != v[i].end(); it++)
    //     {
    //         cout << (*it).name << " " << (*it).marks << endl;
    //     }
    // }
}

int main()
{
    student s[1000];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i].name >> s[i].marks;
    }

    bucketSort(s, n);

    return 0;
}