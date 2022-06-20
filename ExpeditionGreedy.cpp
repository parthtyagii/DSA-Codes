#include <iostream>
#include <climits>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <set>
#include <map>
using namespace std;

bool compare(pair<long long, long long> p1, pair<long long, long long> p2)
{
    return p1.first > p2.first;
}

int main()
{
    long long n, d, f, Dis, Fuel;
    cin >> n;

    vector<pair<long long, long long>> v;
    priority_queue<long long> q;

    for (long long i = 0; i < n; i++)
    {
        cin >> d >> f;
        v.push_back(make_pair(d, f));
    }
    sort(v.begin(), v.end(), compare);

    cin >> Dis >> Fuel;

    for (long long i = 0; i < n; i++)
    {
        v[i].first = Dis - v[i].first;
    }

    // for (auto p : v)
    // {
    //     cout << p.first << " ";
    // }

    long prev = 0;
    long long x = 0;
    long long ans = 0;
    bool check = false;
    while (x < n)
    {
        if ((v[x].first - prev) <= Fuel)
        {
            Fuel = Fuel - (v[x].first - prev);
            q.push(v[x].second);
            prev = v[x].first;
        }
        else
        {
            if (q.empty())
            {
                check = true;
                break;
            }

            Fuel += q.top();
            q.pop();
            ans += 1;
            continue;
        }
        x++;
    }

    if (check)
    {
        return -1;
    }

    Dis = Dis - v[n - 1].first;
    if (Fuel >= Dis)
    {
        cout << ans << endl;
        return 0;
    }

    while (Fuel < Dis)
    {
        if (q.empty())
        {
            check = true;
            break;
        }

        Fuel += q.top();
        q.pop();
        ans += 1;
    }

    if (check)
    {
        return -1;
    }

    cout << ans << endl;

    return 0;
}