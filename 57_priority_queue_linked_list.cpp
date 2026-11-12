// Q57 AIM: Implement a linked-list priority queue with insertion, deletion and display.
#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string patient;
    int priority;
    Node *next;
    Node(string name, int value) : patient(name), priority(value), next(nullptr) {}
};

class PriorityQueue
{
    Node *front = nullptr;

public:
    ~PriorityQueue()
    {
        while (front)
        {
            Node *temp = front;
            front = front->next;
            delete temp;
        }
    }

    void insert(const string &name, int priority)
    {
        Node *node = new Node(name, priority);
        if (!front || priority > front->priority)
        {
            node->next = front;
            front = node;
            return;
        }

        Node *current = front;
        while (current->next && current->next->priority >= priority)
            current = current->next;
        node->next = current->next;
        current->next = node;
    }

    void removeHighest()
    {
        if (!front)
        {
            cout << "Priority queue is empty" << endl;
            return;
        }
        Node *temp = front;
        cout << "Attending patient: " << temp->patient
             << " (priority " << temp->priority << ")" << endl;
        front = front->next;
        delete temp;
    }

    void display()
    {
        for (Node *p = front; p; p = p->next)
            cout << p->patient << "(" << p->priority << ") -> ";
        cout << "NULL" << endl;
    }
};

int main()
{
    PriorityQueue q;
    int choice, priority;
    string name;
    do
    {
        cout << "1.Insert patient 2.Attend highest priority 3.Display 0.Exit: ";
        cin >> choice;
        if (choice == 1) cin >> name >> priority, q.insert(name, priority);
        else if (choice == 2) q.removeHighest();
        else if (choice == 3) q.display();
    } while (choice != 0);
    return 0;
}