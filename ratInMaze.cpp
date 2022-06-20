#include <iostream>
using namespace std;

bool ratInMaze(char maze[10][10], int soln[10][10], int i, int j, int m, int n)
{
    if (i == m - 1 and j == n - 1)
    {
        // Base condition:
        soln[i][j] = 1;
        // Print path:
        for (int p = 0; p < m; p++)
        {
            for (int q = 0; q < n; q++)
            {
                cout << soln[p][q] << " ";
            }
            cout << endl;
        }
        cout << endl;

        return true;
    }

    if (i > m - 1 or j > n - 1)
    {
        return false;
    }
    if (maze[i][j] == 'X')
    {
        return false;
    }

    soln[i][j] = 1;

    // check path right and down side: Recursive case.
    bool rightSuccess = ratInMaze(maze, soln, i, j + 1, m, n);
    bool downSuccess = ratInMaze(maze, soln, i + 1, j, m, n);

    // Backtracking:
    soln[i][j] = 0;

    if (rightSuccess or downSuccess)
    {
        return true;
    }
    return false;
}

int main()
{
    char maze[][10] = {"0000",
                       "00X0",
                       "000X",
                       "0X00"};

    int soln[10][10] = {0};
    int m = 4;
    int n = 4;

    bool ans = ratInMaze(maze, soln, 0, 0, m, n);
    if (ans == false)
    {
        cout << "No path exist" << endl;
    }

    return 0;
}