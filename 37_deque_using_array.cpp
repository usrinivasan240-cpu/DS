// Q37 AIM: Implement deque insertion and deletion at both ends using an array.
#include <iostream>
using namespace std;

class Deque
{
    static const int SIZE = 6;
    int data[SIZE];
    int front = 0, rear = -1, count = 0;

public:
    void insertFront(int value)
    {
        if (count == SIZE) { cout << "Deque is full" << endl; return; }
        front = (front - 1 + SIZE) % SIZE;
        data[front] = value;
        if (count == 0) rear = front;
        count++;
    }

    void insertRear(int value)
    {
        if (count == SIZE) { cout << "Deque is full" << endl; return; }
        rear = (rear + 1) % SIZE;
        data[rear] = value;
        if (count == 0) front = rear;
        count++;
    }

    void deleteFront()
    {
        if (count == 0) { cout << "Deque is empty" << endl; return; }
        cout << "Deleted: " << data[front] << endl;
        front = (front + 1) % SIZE;
        count--;
        if (count == 0) rear = -1, front = 0;
    }

    void deleteRear()
    {
        if (count == 0) { cout << "Deque is empty" << endl; return; }
        cout << "Deleted: " << data[rear] << endl;
        rear = (rear - 1 + SIZE) % SIZE;
        count--;
        if (count == 0) rear = -1, front = 0;
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
    Deque dq;
    int choice, value;
    do
    {
        cout << "1.Insert front 2.Insert rear 3.Delete front 4.Delete rear 5.Display 0.Exit: ";
        cin >> choice;
        if (choice == 1) cin >> value, dq.insertFront(value);
        else if (choice == 2) cin >> value, dq.insertRear(value);
        else if (choice == 3) dq.deleteFront();
        else if (choice == 4) dq.deleteRear();
        else if (choice == 5) dq.display();
    } while (choice != 0);
    return 0;
}