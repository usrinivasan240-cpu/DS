#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int> &a)
{
    for (int i = 1; i < (int)a.size(); i++)
    {
        int key = a[i], j = i - 1;
        while (j >= 0 && a[j] > key)
            a[j + 1] = a[j], j--;
        a[j + 1] = key;
    }
}

void merge(vector<int> &a, int left, int mid, int right)
{
    vector<int> temp;
    int i = left, j = mid + 1;
    while (i <= mid && j <= right)
        temp.push_back(a[i] <= a[j] ? a[i++] : a[j++]);
    while (i <= mid) temp.push_back(a[i++]);
    while (j <= right) temp.push_back(a[j++]);
    for (int k = left; k <= right; k++)
        a[k] = temp[k - left];
}

void mergeSort(vector<int> &a, int left, int right)
{
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSort(a, left, mid);
    mergeSort(a, mid + 1, right);
    merge(a, left, mid, right);
}

void display(const vector<int> &a)
{
    for (int value : a) cout << value << " ";
    cout << endl;
}

int main()
{
    int n;
    cout << "Number of values: ";
    cin >> n;
    vector<int> values(n);
    for (int &value : values) cin >> value;

    vector<int> first = values, second = values;
    insertionSort(first);
    mergeSort(second, 0, n - 1);

    cout << "Insertion sort: ";
    display(first);
    cout << "Merge sort: ";
    display(second);
    return 0;
}