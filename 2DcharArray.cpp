#include <iostream>
using namespace std;

// 2D-Char-Array:

int main()
{
    char a[][10] = {{'p', 'a', 'r', '\0'}, {' ','t', 'h', '\0'}};
    char b[10][10];
    b[0][4] = 'i';
    char c[][10] = {"delhi", "college"};

    cout << a[0] << a[1] << endl;
    cout << b[0][4] << endl;
    cout << c[0] << c[1] << endl;

    return 0;
}
