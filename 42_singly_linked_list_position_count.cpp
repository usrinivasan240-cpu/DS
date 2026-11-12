// Q42 AIM: Insert and delete linked-list nodes at a position and count the nodes.
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList
{
    Node *head = nullptr;

public:
    ~LinkedList()
    {
        while (head)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }

    void insertAt(int position, int value)
    {
        if (position < 1) { cout << "Invalid position" << endl; return; }
        Node *node = new Node(value);
        if (position == 1)
        {
            node->next = head;
            head = node;
            return;
        }
        Node *current = head;
        for (int i = 1; current && i < position - 1; i++)
            current = current->next;
        if (!current) { delete node; cout << "Invalid position" << endl; return; }
        node->next = current->next;
        current->next = node;
    }

    void deleteAt(int position)
    {
        if (position < 1 || !head) { cout << "Invalid position" << endl; return; }
        Node *current = head;
        if (position == 1) head = head->next;
        else
        {
            Node *previous = nullptr;
            for (int i = 1; current && i < position; i++)
                previous = current, current = current->next;
            if (!current) { cout << "Invalid position" << endl; return; }
            previous->next = current->next;
        }
        delete current;
    }

    void displayAndCount()
    {
        int count = 0;
        for (Node *p = head; p; p = p->next)
            cout << p->data << " ", count++;
        cout << "\nTotal nodes: " << count << endl;
    }
};

int main()
{
    LinkedList list;
    int choice, position, value;
    do
    {
        cout << "1.Insert at position 2.Delete at position 3.Display/count 0.Exit: ";
        cin >> choice;
        if (choice == 1) cin >> position >> value, list.insertAt(position, value);
        else if (choice == 2) cin >> position, list.deleteAt(position);
        else if (choice == 3) list.displayAndCount();
    } while (choice != 0);
    return 0;
}