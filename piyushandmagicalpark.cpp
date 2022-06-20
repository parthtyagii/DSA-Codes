#include <iostream>
using namespace std;

// Piyush and Magical park:

void magicalpark(char arr[100][100], int n, int m, int k, int s)
{
    bool beta = true;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char alpha = arr[i][j];

            if (s < k)
            {
                beta = false;
                break;
            }
            else if (alpha == '.')
            {
                s = s - 2;
            }
            else if (alpha == '*')
            {
                s += 5;
            }
            else if (alpha == '#')
            {
                break;
            }

            if (j != m - 1)
            {
                s = s - 1;
            }
        }
    }
    if (beta)
    {
        cout << "yes" << endl
             << s << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}

int main()
{
    int n, m, k, s;
    cin >> n >> m >> k >> s;

    char arr[100][100];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    magicalpark(arr, n, m, k, s);

    return 0;
}
