#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

// Hash Function: for custom class...

class student
{
public:
    string firstname;
    string lastname;
    int rollno;

    student(string f, string l, int r)
    {
        firstname = f;
        lastname = l;
        rollno = r;
    }

    // To compare the students:
    bool operator==(const student &s) const
    {
        if (rollno == s.rollno)
        {
            return true;
        }
        return false;
    }
};

// Custom Hash function for student class:
class hashfn
{
public:
    //
    size_t operator()(const student &s) const
    {
        return (s.firstname.length() + s.lastname.length());
    }
};

int main()
{
    student s1("parth", "tyagi", 40);
    student s2("parth", "joshi", 29);
    student s3("tushar", "garg", 19);
    student s4("rohan", "walia", 47);
    student s5("himanshu", "maggo", 85);

    // map students: have to use unordered map.
    unordered_map<student, int, hashfn> m;
    m[s1] = 1001;
    m[s2] = 1002;
    m[s3] = 1003;
    m[s4] = 1004;
    m[s5] = 1005;

    // find:
    cout << m[s2] << endl;

    // iterate:
    for (auto p : m)
    {
        cout << p.first.firstname << " -> " << p.first.rollno << " -> " << p.second << endl;
    }

    return 0;
}