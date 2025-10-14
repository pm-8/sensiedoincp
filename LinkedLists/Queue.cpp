#include <iostream>
using namespace std;

class Queue {
    int *arr;
    int capacity;
    int front;
    int rear;

public:   // <-- make methods public
    Queue(int n) {
        capacity = n;
        arr = new int[capacity];
        front = 0;
        rear = 0;
    }

    void enqueue(int num) {
        if (rear == capacity) {
            cout << "Overflow\n";
            return;
        }
        arr[rear] = num;
        rear++;
    }

    void dequeue() {
        if (front == rear) {
            cout << "Underflow\n";
            return;
        }
        cout << "Dequeued: " << arr[front] << endl;
        front++;
    }

    void display() {
        if (front == rear) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Queue: ";
        for (int i = front; i < rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    q.dequeue();
    q.display();
    return 0;
}
