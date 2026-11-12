// Q22 AIM: Perform singly linked-list insertion, search and deletion operations.
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
        if (position < 1)
        {
            cout << "Invalid position" << endl;
            return;
        }
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
        if (!current)
        {
            delete node;
            cout << "Invalid position" << endl;
            return;
        }
        node->next = current->next;
        current->next = node;
    }

    void insertEnd(int value)
    {
        Node *node = new Node(value);
        if (!head)
        {
            head = node;
            return;
        }
        Node *current = head;
        while (current->next) current = current->next;
        current->next = node;
    }

    void search(int key)
    {
        int position = 1;
        for (Node *p = head; p; p = p->next, position++)
            if (p->data == key)
            {
                cout << "Found at position " << position << endl;
                return;
            }
        cout << "Not found" << endl;
    }

    void deleteValue(int key)
    {
        Node *current = head, *previous = nullptr;
        while (current && current->data != key)
            previous = current, current = current->next;
        if (!current)
        {
            cout << "Value not found" << endl;
            return;
        }
        if (previous) previous->next = current->next;
        else head = current->next;
        delete current;
    }

    void display()
    {
        for (Node *p = head; p; p = p->next)
            cout << p->data << " -> ";
        cout << "NULL" << endl;
    }
};

int main()
{
    LinkedList list;
    int choice, position, value;
    do
    {
        cout << "1.Beginning 2.End 3.Position 4.Search 5.Delete 6.Display 0.Exit: ";
        cin >> choice;
        if (choice == 1) cin >> value, list.insertAt(1, value);
        else if (choice == 2) cin >> value, list.insertEnd(value);
        else if (choice == 3) cin >> position >> value, list.insertAt(position, value);
        else if (choice == 4) cin >> value, list.search(value);
        else if (choice == 5) cin >> value, list.deleteValue(value);
        else if (choice == 6) list.display();
    } while (choice != 0);
    return 0;
}