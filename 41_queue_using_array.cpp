#include <iostream>
#include <string>
using namespace std;

class Queue
{
    static const int SIZE = 5;
    string customers[SIZE];
    int front = 0, rear = -1, count = 0;

public:
    void enqueue(const string &name)
    {
        if (count == SIZE)
        {
            cout << "Queue is full" << endl;
            return;
        }
        rear = (rear + 1) % SIZE;
        customers[rear] = name;
        count++;
    }

    void dequeue()
    {
        if (count == 0)
        {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Served customer: " << customers[front] << endl;
        front = (front + 1) % SIZE;
        count--;
    }

    void display()
    {
        if (count == 0) cout << "Queue is empty";
        for (int i = 0; i < count; i++)
            cout << customers[(front + i) % SIZE] << " ";
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
        if (choice == 1) cin >> name, q.enqueue(name);
        else if (choice == 2) q.dequeue();
        else if (choice == 3) q.display();
    } while (choice != 0);
    return 0;
}