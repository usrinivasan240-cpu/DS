// Q35 AIM: Implement doubly linked-list insertion, deletion and forward/backward display.
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *previous, *next;
    Node(int value) : data(value), previous(nullptr), next(nullptr) {}
};

class DoublyLinkedList
{
    Node *head = nullptr, *tail = nullptr;

public:
    ~DoublyLinkedList()
    {
        while (head)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }

    void insert(int value)
    {
        Node *node = new Node(value);
        node->previous = tail;
        if (tail) tail->next = node;
        else head = node;
        tail = node;
    }

    void remove(int value)
    {
        Node *current = head;
        while (current && current->data != value)
            current = current->next;
        if (!current)
        {
            cout << "Value not found" << endl;
            return;
        }
        if (current->previous) current->previous->next = current->next;
        else head = current->next;
        if (current->next) current->next->previous = current->previous;
        else tail = current->previous;
        delete current;
    }

    void display()
    {
        cout << "Forward: ";
        for (Node *p = head; p; p = p->next) cout << p->data << " ";
        cout << "\nBackward: ";
        for (Node *p = tail; p; p = p->previous) cout << p->data << " ";
        cout << endl;
    }
};

int main()
{
    DoublyLinkedList list;
    int choice, value;
    do
    {
        cout << "1.Insert 2.Delete 3.Display 0.Exit: ";
        cin >> choice;
        if (choice == 1) cin >> value, list.insert(value);
        else if (choice == 2) cin >> value, list.remove(value);
        else if (choice == 3) list.display();
    } while (choice != 0);
    return 0;
}