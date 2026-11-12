// Q28 AIM: Build a max heap from input and delete the maximum element.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void heapify(vector<int> &heap, int n, int i)
{
    int largest = i, left = 2 * i + 1, right = 2 * i + 2;
    if (left < n && heap[left] > heap[largest]) largest = left;
    if (right < n && heap[right] > heap[largest]) largest = right;
    if (largest != i)
    {
        swap(heap[i], heap[largest]);
        heapify(heap, n, largest);
    }
}

int main()
{
    int n;
    cout << "Number of values: ";
    cin >> n;
    vector<int> heap(n);
    for (int &value : heap) cin >> value;

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(heap, n, i);

    cout << "Max heap: ";
    for (int value : heap) cout << value << " ";

    if (!heap.empty())
    {
        cout << "\nDeleted maximum: " << heap[0] << endl;
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty()) heapify(heap, heap.size(), 0);
    }

    cout << "Updated heap: ";
    for (int value : heap) cout << value << " ";
    cout << endl;
    return 0;
}