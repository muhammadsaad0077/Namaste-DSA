#include <iostream>
using namespace std;

class Queue {
public:
    int size, len, front, rear;
    int arr[5];

    Queue() {
        size = 5;
        len = 0;
        front = -1;
        rear = -1;
    }

    void enqueue(int val) {
        if (len == size) {
            cout << "Queue full\n";
            return;
        }
        if (front == -1) front = 0;
        arr[++rear] = val;
        len++;
    }

    int dequeue() {
        if (len == 0) {
            cout << "Queue empty\n";
            return -1;
        }
        int val = arr[front++];
        len--;
        if (len == 0) {
            front = -1;
            rear = -1;
        }
        return val;
    }

    void display() {
        if (len == 0) {
            cout << "Queue empty\n";
            return;
        }
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    q.dequeue();
    q.dequeue();

    q.display();
    return 0;
}
