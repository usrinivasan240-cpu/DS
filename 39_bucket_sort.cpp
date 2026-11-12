#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<double> values = {0.42, 0.32, 0.23, 0.52, 0.25, 0.47, 0.51};
    const int bucketCount = values.size();
    vector<vector<double>> buckets(bucketCount);

    for (double value : values)
    {
        int index = static_cast<int>(value * bucketCount);
        if (index >= bucketCount) index = bucketCount - 1;
        buckets[index].push_back(value);
    }

    for (int i = 0; i < bucketCount; i++)
        sort(buckets[i].begin(), buckets[i].end());

    cout << "Sorted values: ";
    for (int i = 0; i < bucketCount; i++)
        for (double value : buckets[i])
            cout << value << " ";
    cout << endl;
    return 0;
}