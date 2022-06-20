#include <iostream>
#include <stack>
using namespace std;

// we need to print the span of current stock price:

void StockSpan(int prices[], int n, int *span)
{

    stack<int> s;
    // for 0th day:
    s.push(0);
    span[0] = 1;

    // for rest of the days:
    for (int i = 1; i < n; i++)
    {
        int curPrice = prices[i];

        while (!s.empty() and prices[s.top()] <= curPrice)
        {
            s.pop();
        }

        if (!s.empty())
        {
            int prev_high = s.top();
            span[i] = i - prev_high;
        }
        else
        {
            span[i] = i + 1;
        }

        s.push(i);
    }
}

int main()
{
    int prices[] = {100, 80, 60, 70, 60, 75, 85};
    int n = sizeof(prices) / sizeof(int);
    int span[100] = {0};

    StockSpan(prices, n, span);

    for (int i = 0; i < n; i++)
    {
        cout << span[i] << " ";
    }

    return 0;
}