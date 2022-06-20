#include <iostream>
using namespace std;

void move(int n, char src, char help, char dest)
{
    if (n <= 0)
    {
        return;
    }

    move(n - 1, src, dest, help);
    cout << "shift " << n << " from " << src << " to " << dest << endl;
    move(n - 1, help, src, dest);
    return;
}

int main()
{
    int n = 0;
    cin >> n;

    move(n, 'A', 'B', 'C');

    return 0;
}
