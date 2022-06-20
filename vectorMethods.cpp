#include <iostream>
#include <vector>
using namespace std;

// Some Methods of Vector:

int main()
{
    vector<int> v{11, 12, 13, 14, 15};
    v.push_back(16); // add to the last of the array. O(1)

    v.pop_back(); // removes the last elements of the array. O(1)

    v.insert(v.begin() + 2, 3, 101); // insert the element at that index.

    v.erase(v.begin() + 2); // erases the element or range of elements.
    v.erase(v.begin() + 2, v.begin() + 4);

    // Now,
    cout << v.size() << endl;
    cout << v.capacity() << endl
         << endl;

    // Resize method: capacity will increase only if size in increasing.
    // we avoid shrink.
    v.resize(2);
    cout << v.size() << endl;
    cout << v.capacity() << endl;

    // clear: doesnot delete the memory allocated.
    v.clear();

    // empty:
    if (v.empty())
    {
        cout << "yes" << endl;
    }

    v.push_back(12);
    v.push_back(13);
    v.push_back(14);
    v.push_back(15);

    // front and back:
    cout << v.front() << endl;
    cout << v.back() << endl;

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << ",";
    }
    cout << endl;

    // Reserve method:
    vector<int> d;
    int n;
    cin >> n;

    d.reserve(100); // stops the the doubling until capacity exceeds 100.

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        d.push_back(x);
        cout << "capacity: " << d.capacity() << endl;
    }

    for (int i = 0; i < d.size(); i++)
    {
        cout << d[i] << " ";
    }

    return 0;
}