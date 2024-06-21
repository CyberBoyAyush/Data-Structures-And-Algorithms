#include<bits/stdc++.h>
using namespace std;

class Dequeue{
    public:
    int * arr;
    int front , rear, size;

    Dequeue(int n){
        size = n;
        front = rear = -1;
        arr = new int[n];
    }

    // isEMpty()
    bool empty(){
        return front == -1;
    }

    // full
    bool full(){
        return (rear + 1) % size == front;
    }

    //push front
    void push_front(int x){
        if(empty()){
            front = rear = 0;
            arr [0] = x;
        }
        if(full()){
            return;
        }
        else{
            front = (front - 1 + size) % size;
            arr[front] = x;
        }
    }

    // push_back
    void push_back(int x){
        if(empty()){
            front = rear = 0;
            arr [0] = x;
        }
        else if(full()){
            return;
        }
        else{
            rear = (rear + 1 + size) % size;
            arr[rear] = x;
        }
    }

    // pop front
    void pop_fornt(){
        if(empty()){
            return;
        }
        else{
            if(front == rear){// single elment hai
                front = rear = -1;
            }
            else{
                front = (front + 1 + size) % size;
            }
        }
    }

    //pop back
    void pop_back(){
        if(empty()){
            return;
        }
        else{
            if(front == rear){
                front = rear = -1;
            }
            else{
                rear = (rear - 1 + size) % size;
            }
        }
    }

    // start
    int start(){
        if(empty()){
            return -1;
        }
        else{
            return arr[front];
        }
    }

    //end
    int end(){
        if(empty()){
            return -1;
        }
        else{
            return arr[rear];
        }
    }

};

int main(){
 Dequeue dq(5);
    dq.push_front(10);
    dq.push_front(20);
    cout<<dq.start()<<endl;
    cout<<dq.end()<<endl;
return 0;
}