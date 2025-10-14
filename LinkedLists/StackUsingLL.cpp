#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    Node(int x){
        data = x;
        next = nullptr;
    }
};
class Stack{
    Node* top;
public:
    Stack(){
        top = nullptr;
    }    
    void push(int num){
        Node* temp = new Node(num);
        temp -> next = top;
        top = temp;
    }
    int pop(){
        if(top == NULL){
            cout << "Stack Underflow" << endl;
            return -1;
        }
        Node* temp = top;
        top = top-> next;
        int val = temp->data;
        delete(temp);
        return val;
    }
    int peek(){
        if(top == nullptr){
            cout << "Stack is Empty" << endl;
            return -1;
        }
        return top->data;
    }
};
int main()
{   
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    // popping one element
    cout << "Popped: " << st.pop() << endl;

    // checking top element
    cout << "Top element: " << st.peek() << endl;

    // checking if stack is empty
    // cout << "Is stack empty: " << (st.isEmpty() ? "Yes" : "No") << endl;

    // checking current size
    // cout << "Current size: " << st.size() << endl;

    // return 0;
    return 0;
}