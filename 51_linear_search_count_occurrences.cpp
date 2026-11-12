// Q51 AIM: Count occurrences of 7 using linear search.
#include <iostream>
using namespace std;

int main()
{
    int values[] = {7, 3, 7, 9, 7, 2, 5};
    int key = 7, count = 0;

    for (int value : values)
        if (value == key) count++;

    if (count == 0) cout << key << " not found" << endl;
    else cout << key << " found " << count << " times" << endl;
    return 0;
}