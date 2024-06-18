#include<bits/stdc++.h>
using namespace std;

// LL craetion
class Node{
    public:
    int data;
    Node * next;

    Node(int val){
        this->data = val;
        this->next = nullptr;
    }
};

// Stack creation
class Stack{
    public:
    Node * top;
    int size;

    Stack(){
        top = nullptr;
        size = 0;
    }

    // push
    void push(int val){
        cout<<val<<" is pushed to stack"<<endl;
        Node* temp = new Node(val);
        temp->next = top;
        top = temp;
        size++; // size counter
    }

    //pop
    void pop(){
        if(top==nullptr){
            cout<<"underflow"<<endl;
        }
        else{
            cout<<top->data<<" is poped to stack"<<endl;
            Node* temp = top;
            top = top->next;
            delete temp;
            size--;
        }
    }

    // Top
    int peak(){
        return top->data;
    }

    int isSize(){
        return size;
    }
};

int main(){
    Stack s;
    s.push(100);
    s.push(100);
    s.push(123);
    cout<<s.peak()<<endl;
    s.pop();
    cout<<s.peak()<<endl;
    
    int a = s.isSize();
    cout<<a<<endl;
    return 0;
}