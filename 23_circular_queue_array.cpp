// Q23 AIM: Implement a circular queue using an array with enqueue and dequeue.
#include <iostream>
using namespace std;

class CircularQueue
{
    static const int SIZE = 5;
    int data[SIZE];
    int front = 0, rear = -1, count = 0;

public:
    void enqueue(int value)
    {
        if (count == SIZE)
        {
            cout << "Queue is full" << endl;
            return;
        }
        rear = (rear + 1) % SIZE;
        data[rear] = value;
        count++;
    }

    void dequeue()
    {
        if (count == 0)
        {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Removed: " << data[front] << endl;
        front = (front + 1) % SIZE;
        count--;
    }

    void display()
    {
        for (int i = 0; i < count; i++)
            cout << data[(front + i) % SIZE] << " ";
        cout << endl;
    }
};

int main()
{
    CircularQueue q;
    int choice, value;
    do
    {
        cout << "1.Enqueue 2.Dequeue 3.Display 0.Exit: ";
        cin >> choice;
        if (choice == 1) cin >> value, q.enqueue(value);
        else if (choice == 2) q.dequeue();
        else if (choice == 3) q.display();
    } while (choice != 0);
    return 0;
}