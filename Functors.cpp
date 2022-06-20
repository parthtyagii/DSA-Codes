#include <iostream>
using namespace std;

// Functors:

class fun
{
public:
    void operator()(string s)
    {
        cout << s << endl;
    }
};

int main()
{
    fun f;
    f("hii"); // it looks like function call...but its not.
        // () are overloaded for 'fun' class objects.

    fun f1;
    f1("hello world!!");

    return 0;
}