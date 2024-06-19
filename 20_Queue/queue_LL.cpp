// Implementation of Queue using Linked List LL
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data = val;
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

    // isEmpty func
    bool isEmpty(){
        return front == nullptr;
    }

    //push func
    void push(int x){
        if(isEmpty()){
            front = new Node(x);
            rear = front;
        }
        else{
            rear->next = new Node(x);
            rear = rear->next;
        }
    }

    // pop func
    void pop(){
        if(isEmpty()){
            cout<< "Queue Empty" <<endl;
        }
        else{
            Node* temp = front;
            front = front->next;
            delete(temp);
        }
    }
    // start func
    int start(){
        if(isEmpty()){
            cout<<"Queue empty"<<endl;
        }
        return front->data;
    }
};

int main(){
 Queue q;
    q.push(10);
    q.push(16);
    cout<< q.start()<<endl;
    q.pop();
    cout<< q.start()<<endl;
return 0;
}