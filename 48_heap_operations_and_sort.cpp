// Q48 AIM: Implement heap insertion/deletion and heap sort.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

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
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);
    for (int i = n - 1; i > 0; i--)
    {
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}

int main()
{
    int n;
    cout << "Number of values: ";
    cin >> n;
    vector<int> values(n);
    for (int &value : values) cin >> value;

    vector<int> heap = values;
    for (int i = (int)heap.size() / 2 - 1; i >= 0; i--)
        heapify(heap, heap.size(), i);

    cout << "Max heap: ";
    for (int value : heap) cout << value << " ";

    if (!heap.empty())
    {
        cout << "\nDeleted maximum: " << heap[0] << endl;
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty()) heapify(heap, heap.size(), 0);
    }

    heapSort(values);
    cout << "Heap sort: ";
    for (int value : values) cout << value << " ";
    cout << endl;
    return 0;
}