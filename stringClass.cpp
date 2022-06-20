#include <iostream>
#include <string>
#include <cstring>
using namespace std;

// String Class: it is a class

int main()
{
    // String initialization:
    string p0;
    string p1 = "hello world!!";
    string p2("hi how are you!!!!!!");

    string p3(p2);
    string p4 = p3;

    char c[] = {'d', 't', 'u', '\0'};
    string p5(c);

    cout << p1 << endl;
    cout << p2 << endl;
    cout << p3 << endl;
    cout << p4 << endl;
    cout << p5 << endl;

    if (p0.empty()) // ' .empty() ' returns bool value.
    {
        cout << "p0 is a empty string" << endl;
    }
    else
    {
        cout << "not empty" << endl;
    }
    char X = 'a';
    // Append: add something to a string.
    p0.append(" is a good college ");
    p0 = p0 + "and " + X;         // here X will join with the string.
    p0 += "a student of it." + X; // here X will not join with the string.
    cout << p0 << endl;

    // Remove from a string:
    cout << p5.length() << endl; // ".length()" gives the length of string class p5. We can't use strlen(p5).
    p5.clear();                  // "strlen()" is only for char array.
    cout << p5.length() << endl;

    // Compare the String: ".compare()" return integer, 0 or >0 or <0.
    cout << p1.compare(p5) << endl;
    cout << p5.compare(p1) << endl;

    // we can use overloaded operators for comparison:
    if (p5 > p1)
    {
        cout << "yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    // Can access 'ith' character of a string.
    cout << p1[4] << endl;

    // Find sub-strings:
    string p = "i am learing from coding blocks";
    int idx = p.find("coding");
    cout << idx << endl;

    // remove sub-string:
    string q = "from";
    idx = p.find("from");
    cout << p << endl;
    p.erase(idx, q.length() + 1);
    cout << p << endl;

    // Iterate over a string:
    for (int i = 0; i < p.length(); i++)
    {
        cout << p[i] << ":";
    }
    cout << endl;

    // We can use Iterators:
    string w = "data structures and algorithm";
    for (string::iterator x = w.begin(); x != w.end(); x++) // can replace 'string::iterator' with 'auto'.
    {
        cout << (*x) << ",";
    }
    cout << endl;

    // For each loop for itertion: (c++ 11)
    for (auto c : w)
    {
        cout << c << ",";
    }

    return 0;
}
