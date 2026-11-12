#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int value, Node *link) : data(value), next(link) {}
};

class Stack
{
    Node *topNode = nullptr;

public:
    ~Stack()
    {
        while (topNode)
        {
            Node *temp = topNode;
            topNode = topNode->next;
            delete temp;
        }
    }

    void push(int value)
    {
        topNode = new Node(value, topNode);
    }

    void pop()
    {
        if (!topNode)
        {
            cout << "Stack underflow" << endl;
            return;
        }
        Node *temp = topNode;
        cout << "Popped: " << temp->data << endl;
        topNode = topNode->next;
        delete temp;
    }

    void display()
    {
        for (Node *p = topNode; p; p = p->next)
            cout << p->data << " ";
        cout << endl;
    }
};

int main()
{
    Stack s;
    int choice, value;
    do
    {
        cout << "1.Push 2.Pop 3.Display 0.Exit: ";
        cin >> choice;
        if (choice == 1) cin >> value, s.push(value);
        else if (choice == 2) s.pop();
        else if (choice == 3) s.display();
    } while (choice != 0);
    return 0;
}