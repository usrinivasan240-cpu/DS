// Q52 AIM: Perform binary search on sorted names and count comparisons.
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int binarySearch(const vector<string> &names, const string &key, int &comparisons)
{
    int low = 0, high = (int)names.size() - 1;
    comparisons = 0;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        comparisons++;
        if (names[mid] == key) return mid;
        if (names[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int main()
{
    int n;
    cout << "Number of names: ";
    cin >> n;
    vector<string> names(n);
    cout << "Enter names in alphabetical order:" << endl;
    for (string &name : names) cin >> name;

    string key;
    cout << "Name to search: ";
    cin >> key;

    int comparisons = 0;
    int position = binarySearch(names, key, comparisons);

    if (position == -1) cout << "Name not found" << endl;
    else cout << "Name found at position " << position + 1 << endl;
    cout << "Comparisons: " << comparisons << endl;
    return 0;
}