#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class car
{
public:
    int x, y;
    car() {}
    car(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    int dist()
    {
        return (x * x + y * y);
    }
};

bool comp(car p1, car p2)
{
    int d1 = p1.dist();
    int d2 = p2.dist();
    if (d1 == d2)
    {
        return p1.x < p2.x;
    }
    return d1 < d2;
}

// bool comp(pair<int, int> p1, pair<int, int> p2)
// {
//     int d1 = p1.first * p1.first + p1.second * p1.second;
//     int d2 = p2.first * p2.first + p2.second * p2.second;
//     if (d1 == d2)
//     {
//         return p1.first < p2.first;
//     }
//     return d1 < d2;
// }

int main()
{
    // First method:

    // vector<pair<int, int>> v;
    // int n;
    // cin >> n;

    // for (int i = 0; i < n; i++)
    // {
    //     int x, y;
    //     cin >> x >> y;
    //     v.push_back(make_pair(x, y));
    // }
    // sort(v.begin(), v.end(), comp);

    // for (int i = 0; i < n; i++)
    // {
    //     cout << "cab location: " << v[i].first << "," << v[i].second << endl;
    // }

    // --------------------------------------------------------------------------------------------------------

    // Second Method:
    vector<car> v;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        car alpha(x, y);
        v.push_back(alpha);
    }
    sort(v.begin(), v.end(), comp);

    for (auto q : v)
    {
        cout << "cab location: " << q.x << "," << q.y << endl;
    }

    return 0;
}
