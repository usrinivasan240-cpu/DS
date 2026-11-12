// Q60 AIM: Find the k-th largest value using a heap without sorting the entire array.
#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int n, k;
    cout << "Number of values: ";
    cin >> n;

    priority_queue<int> maxHeap;
    cout << "Enter values: ";
    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;
        maxHeap.push(value);
    }

    cout << "Enter k: ";
    cin >> k;

    if (k < 1 || k > n)
    {
        cout << "Invalid value of k" << endl;
        return 0;
    }

    for (int i = 1; i < k; i++)
        maxHeap.pop();

    cout << k << "-th largest element: " << maxHeap.top() << endl;
    return 0;
}