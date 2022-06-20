#include <iostream>
#include <cstring>
#include <string>
using namespace std;

// String Tokenization: for character array.

int main()
{
    char ch[100] = "hello, My, name, is, parth!!!";
    char *p = strtok(ch, " "); // strtok() returns a char pointer.
    cout << p << endl;

    while (p != NULL)
    {
        p = strtok(NULL, " ");
        cout << p << endl;
    }

    return 0;
}
