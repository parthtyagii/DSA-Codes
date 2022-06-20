#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
using namespace std;

// Wines Problem:

// Top-Down approach:
int Profit1(int wines[], int start, int last, int year, int dp[][100])
{
    // base case:
    if (start > last)
    {
        return 0;
    }

    // look up:
    if (dp[start][last] != 0)
    {
        return dp[start][last];
    }

    int op1 = wines[start] * year + Profit1(wines, start + 1, last, year + 1, dp);
    int op2 = wines[last] * year + Profit1(wines, start, last - 1, year + 1, dp);

    return dp[start][last] = max(op1, op2);
}

// Bottom Up approach:
int Profit2(wines, start, last, year)
{
    int dp[100][100] = {0};

    for(int j=0;j<last;j++){
        int i=0;
        while(i<last and j<last){
            
            dp[i][j]=







        }







    }








}

int main()
{
    int wines[] = {2, 3, 5, 1, 4};
    int n = sizeof(wines) / sizeof(int);
    int y = 1;
    int dp[100][100] = {0};

    cout << "First approach: ";
    cout << Profit1(wines, 0, n - 1, y, dp) << endl;

    return 0;
}