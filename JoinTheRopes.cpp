#include <iostream>
#include <queue>
using namespace std;

int joinRopes(int *ropes, int n)
{

    int count = 0;
    priority_queue<int, vector<int>, greater<int>> pq(ropes, ropes + n);
    while (pq.size() > 1)
    {
        int A = pq.top();
        pq.pop();

        int B = pq.top();
        pq.pop();

        int new_ropes = (A + B);
        count += new_ropes;
        pq.push(new_ropes);
    }

    return count;
}

int main()
{
    int ropes[] = {4, 3, 2, 6};
    int n = 4;

    cout << joinRopes(ropes, n) << endl;

    return 0;
}