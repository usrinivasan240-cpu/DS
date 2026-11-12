#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int main()
{
    int rows, columns;
    cout << "Enter rows and columns: ";
    cin >> rows >> columns;

    vector<tuple<int, int, int>> triplets;
    cout << "Enter matrix elements:" << endl;

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
        {
            int value;
            cin >> value;
            if (value != 0) triplets.push_back({i, j, value});
        }

    cout << "Triplet representation (row column value):" << endl;
    cout << rows << " " << columns << " " << triplets.size() << endl;
    for (auto [row, column, value] : triplets)
        cout << row << " " << column << " " << value << endl;

    sort(triplets.begin(), triplets.end(), [](const auto &a, const auto &b)
    {
        if (get<1>(a) != get<1>(b)) return get<1>(a) < get<1>(b);
        return get<0>(a) < get<0>(b);
    });

    cout << "Transpose triplets:" << endl;
    cout << columns << " " << rows << " " << triplets.size() << endl;
    for (auto [row, column, value] : triplets)
        cout << column << " " << row << " " << value << endl;
    return 0;
}