#include <iostream>
using namespace std;

struct Node
{
    int position;
    Node *next;
    Node(int value) : position(value), next(nullptr) {}
};

int main()
{
    const int n = 7, k = 3;
    Node *head = nullptr, *tail = nullptr;

    for (int i = 1; i <= n; i++)
    {
        Node *node = new Node(i);
        if (!head) head = tail = node;
        else tail->next = node, tail = node;
    }
    tail->next = head;

    Node *previous = tail, *current = head;
    cout << "Elimination order: ";
    while (current->next != current)
    {
        for (int count = 1; count < k; count++)
            previous = current, current = current->next;

        cout << current->position << " ";
        previous->next = current->next;
        delete current;
        current = previous->next;
    }

    cout << "\nSurvivor: " << current->position << endl;
    delete current;
    return 0;
}