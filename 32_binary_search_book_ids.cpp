#include <iostream>
using namespace std;

int binarySearch(int a[], int n, int key)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (a[mid] == key) return mid;
        if (a[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int main()
{
    int books[] = {5, 12, 18, 27, 33, 41, 56, 72};
    for (int key : {33, 60})
    {
        int position = binarySearch(books, 8, key);
        if (position == -1) cout << key << " is not present" << endl;
        else cout << key << " found at position " << position + 1 << endl;
    }
    return 0;
}