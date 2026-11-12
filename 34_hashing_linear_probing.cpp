#include <iostream>
using namespace std;

int main()
{
    const int SIZE = 10;
    int table[SIZE];
    for (int &slot : table) slot = -1;

    int keys[] = {31, 22, 43, 54, 65, 76};
    for (int key : keys)
    {
        int index = key % SIZE;
        int start = index;

        while (table[index] != -1)
        {
            index = (index + 1) % SIZE;
            if (index == start)
            {
                cout << "Hash table is full" << endl;
                return 0;
            }
        }
        table[index] = key;
    }

    cout << "Index\tValue" << endl;
    for (int i = 0; i < SIZE; i++)
        cout << i << "\t" << (table[i] == -1 ? -1 : table[i]) << endl;
    return 0;
}