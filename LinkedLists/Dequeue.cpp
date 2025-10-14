#include<iostream>
using namespace std;
class Dequeue{
    public:
    int *arr;
    int front;
    int rear;
    int capacity;
    Dequeue(int n){
        capacity = n;
        arr = new int[capacity];
        front = 0;
        rear  = 0;
    }
    void insertFront(int num){
        if(rear == capacity){
            cout << "Overflow" << endl;
            return;
        }
        for(int i = 0; i < rear; i++){
            arr[i+1] = arr[i];
        }
        arr[front] = num;
        rear++;
    }
    void insertRear(int num){
        if(rear == capacity){
            cout << "Overflow" << endl;
            return;
        }
        arr[rear] = num;
        rear++;
    }
    void deleteFront(){
        if(rear == 0){
            cout << "Underflow" << endl;
            return;
        }
        for(int i = rear-1; i >= 1; i--){
            arr[i-1] = arr[i]; 
        }
        rear--;
    }
    void deleteRear(){
        if(rear == 0){
            cout << "Underflow" << endl;
            return;
        }
        rear--;
    }
    void display(){
        if(rear == 0){
            cout << "Dequeue is empty" << endl;
            return;
        }

        for(int i = 0; i < rear; i++) cout << arr[i] << " ";
        cout << endl;
    }
};
int main()
{
    Dequeue dq(5);
    dq.insertFront(1);
    dq.display();
    dq.insertFront(2);
    dq.display();
    dq.insertRear(3);
    dq.display();
    dq.deleteFront();
    dq.display();
    dq.deleteFront();
    dq.display();
    dq.deleteFront();
    dq.display();
    return 0;
}