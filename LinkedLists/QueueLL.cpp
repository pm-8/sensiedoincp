#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    Node(int num){
        data = num;
        next = nullptr;
    }
};
class Queue{
public:
    Node* front;
    Node* rear;
    Queue(){
        front = rear = nullptr;
    }
    void enqueue(int num){
        Node* node = new Node(num);
        if(front == nullptr){
            front = rear = node;
        }
        else{
            rear->next = node;
            rear = node;
        }
    }
    int dequeue(){
        if(front == nullptr){
            cout << "Queue Underflow" << endl;
            return -1;
        }
        Node* temp = front;
        int removedData = temp -> data;
        front = front-> next;
        if(!front) rear = nullptr;
        delete temp;
        return removedData;
    }
};
int main()
{
    return 0;
}