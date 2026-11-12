#include <iostream>
using namespace std;

int main()
{
    const int SIZE = 10;
    int table[SIZE];
    for (int &slot : table) slot = -1;

    int keys[] = {89, 18, 49, 58, 69};
    for (int key : keys)
    {
        bool inserted = false;
        int home = key % SIZE;

        for (int i = 0; i < SIZE; i++)
        {
            int index = (home + i * i) % SIZE;
            if (table[index] == -1)
            {
                table[index] = key;
                inserted = true;
                break;
            }
        }

        if (!inserted)
            cout << "Could not insert " << key << endl;
    }

    cout << "Index\tValue" << endl;
    for (int i = 0; i < SIZE; i++)
        cout << i << "\t" << table[i] << endl;
    return 0;
}