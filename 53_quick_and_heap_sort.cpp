#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int partitionArray(vector<int> &a, int low, int high)
{
    int pivot = a[high], i = low;
    for (int j = low; j < high; j++)
        if (a[j] <= pivot) swap(a[i++], a[j]);
    swap(a[i], a[high]);
    return i;
}

void quickSort(vector<int> &a, int low, int high)
{
    if (low >= high) return;
    int pivot = partitionArray(a, low, high);
    quickSort(a, low, pivot - 1);
    quickSort(a, pivot + 1, high);
}

void heapify(vector<int> &a, int n, int i)
{
    int largest = i, left = 2 * i + 1, right = 2 * i + 2;
    if (left < n && a[left] > a[largest]) largest = left;
    if (right < n && a[right] > a[largest]) largest = right;
    if (largest != i)
    {
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}

void heapSort(vector<int> &a)
{
    int n = a.size();
    for (int i = n / 2 - 1; i >= 0; i--) heapify(a, n, i);
    for (int i = n - 1; i > 0; i--)
    {
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}

void display(const vector<int> &a)
{
    for (int value : a) cout << value << " ";
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    vector<int> values(n);
    for (int &value : values) cin >> value;

    vector<int> quick = values, heap = values;
    quickSort(quick, 0, (int)quick.size() - 1);
    heapSort(heap);

    cout << "Quick sort: ";
    display(quick);
    cout << "Heap sort: ";
    display(heap);
    return 0;
}