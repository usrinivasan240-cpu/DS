// Q20 AIM: Reverse a singly linked list and find its middle node.
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int value) : data(value), next(nullptr) {}
};

void display(Node *head)
{
    while (head)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

Node *reverseList(Node *head)
{
    Node *previous = nullptr;
    Node *current = head;

    while (current)
    {
        Node *nextNode = current->next;
        current->next = previous;
        previous = current;
        current = nextNode;
    }
    return previous;
}

int main()
{
    int n, value;
    cout << "Number of records: ";
    cin >> n;

    Node *head = nullptr, *tail = nullptr;
    for (int i = 0; i < n; i++)
    {
        cin >> value;
        Node *node = new Node(value);
        if (!head) head = tail = node;
        else tail->next = node, tail = node;
    }

    cout << "Original list: ";
    display(head);

    Node *slow = head, *fast = head;
    while (fast && fast->next)
        slow = slow->next, fast = fast->next->next;

    if (slow) cout << "Middle node: " << slow->data << endl;

    head = reverseList(head);
    cout << "Reversed list: ";
    display(head);
    return 0;
}