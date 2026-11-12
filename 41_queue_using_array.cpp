// Q41 AIM: Implement a simple array queue with enqueue, dequeue and display.
#include <iostream>
#include <string>
using namespace std;

class Queue
{
    static const int SIZE = 5;
    string customers[SIZE];
    int front = 0;
    int rear = -1;

public:
    void enqueue(const string &name)
    {
        if (rear == SIZE - 1)
        {
            cout << "Queue is full" << endl;
            return;
        }
        customers[++rear] = name;
    }

    void dequeue()
    {
        if (front > rear)
        {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Served customer: " << customers[front++] << endl;
    }

    void display()
    {
        if (front > rear)
        {
            cout << "Queue is empty" << endl;
            return;
        }
        for (int i = front; i <= rear; i++)
            cout << customers[i] << " ";
        cout << endl;
    }
};

int main()
{
    Queue q;
    int choice;
    string name;

    do
    {
        cout << "1.Enqueue 2.Dequeue 3.Display 0.Exit: ";
        cin >> choice;
        if (choice == 1)
        {
            cout << "Customer name: ";
            cin >> name;
            q.enqueue(name);
        }
        else if (choice == 2) q.dequeue();
        else if (choice == 3) q.display();
    } while (choice != 0);

    return 0;
}
