// Implement Queue using Circular Array

#include<bits/stdc++.h>
using namespace std;

class Queue{
    int * arr;
    int front, rear;
    int size;

    public:
    //constructor
    Queue(int n){
        arr = new int[n];
        front = rear = -1;
        size = n;
    }
    
    // is Empty func
    bool isEmpty(){
        return front==-1;
    }

    //isFull func
    bool isFull(){
        return (rear + 1) % size == front; // change from simple array
    }
    
    // push func
    void push(int x){
        // agar queue khali hai
        if(isEmpty()){
            cout<< x << " is pushed"<<endl;
            front = rear = 0;
            arr[0] = x; 
        }
        else if(isFull()){
            cout<<"Queue overflow"<<endl;
        }
        else{
            rear = (rear + 1) % size;
            arr[rear] = x;
            cout<< x << " is pushed"<<endl;
        }
    }

    // pop func
    void pop(){
        if(isEmpty()){
            cout<< "Queue empty"<<endl;
        }
        else{
            if(front==rear){ // ek hi element hai
                front = rear = -1;
            }
            else{
                front = (front + 1) % size;
                cout<<"element is popped"<<endl;
            }
        }
    }

    //start func
    int start(){
        if(isEmpty()){
            cout<<"Empty Queue"<<endl;
            return -1;
        }
        return arr[front];
    }
};

int main(){
    Queue q(5);
    q.push(10);
    q.push(16);
    cout<< q.start()<<endl;
    q.pop();
    cout<< q.start()<<endl;
return 0;
}