// Q58 AIM: Merge two sorted arrays into one sorted array.
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    cout << "Number of elements in first array: ";
    cin >> n;
    vector<int> a(n);
    cout << "Enter first sorted array: ";
    for (int &value : a) cin >> value;

    cout << "Number of elements in second array: ";
    cin >> m;
    vector<int> b(m);
    cout << "Enter second sorted array: ";
    for (int &value : b) cin >> value;

    vector<int> merged;
    int i = 0, j = 0;

    while (i < n && j < m)
    {
        if (a[i] <= b[j]) merged.push_back(a[i++]);
        else merged.push_back(b[j++]);
    }
    while (i < n) merged.push_back(a[i++]);
    while (j < m) merged.push_back(b[j++]);

    cout << "Merged sorted array: ";
    for (int value : merged) cout << value << " ";
    cout << endl;
    return 0;
}