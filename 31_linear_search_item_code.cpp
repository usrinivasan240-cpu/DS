// Q31 AIM: Search for item code 47 using linear search.
#include <iostream>
using namespace std;

int main()
{
    int items[] = {14, 8, 29, 3, 47, 21, 35};
    int size = 7, key = 47, position = -1;

    for (int i = 0; i < size; i++)
        if (items[i] == key)
        {
            position = i;
            break;
        }

    if (position == -1) cout << key << " not found" << endl;
    else cout << key << " found at position " << position + 1 << endl;
    return 0;
}