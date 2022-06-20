#include <iostream>
using namespace std;

int knapsack(int n, int cw, int *weight, int *prices)
{
    if (n == 0 || cw == 0)
    {
        return 0;
    }

    int ans = 0;
    int inc = 0;
    int exc = 0;
    // including last item
    if (weight[n - 1] <= cw)
    {
        inc = prices[n - 1] + knapsack(n - 1, cw - weight[n - 1], weight, prices);
    }
    //excluding last item
    exc = knapsack(n - 1, cw, weight, prices);

    ans = max(inc, exc);

    return ans;
}

int main()
{
    int weight[] = {1, 2, 5, 3};
    int prices[] = {40, 20, 30, 100};
    int n = 4;
    int cw = 7;

    cout << knapsack(n, cw, weight, prices);

    return 0;
}