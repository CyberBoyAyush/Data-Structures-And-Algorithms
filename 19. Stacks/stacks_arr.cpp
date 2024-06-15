#include <bits/stdc++.h>
using namespace std;

class Stack{
    int *arr;
    int size;
    int top;

    public:
    Stack(int s){
        size = s;
        top = -1;
        arr = new int[s];
    }

    // push func
    void push(int val){
        if(top == size-1){
            cout<<"Stack Overflow"<<endl;
        }
        else{
            top++;
            arr[top] = val;
            cout<< arr[top]<< " has been added to your stack"<<endl;
        }
    }


    //pop func
    void pop(){
        if(top==-1){
            cout<<"stack underflow";
        }
        else{
            cout<< arr[top] << " has been popped from stack"<<endl;
            top--;
        }
    }

    //is empty
    bool isEmpty(){
        return top==-1;
    }

    // top values
    int peak(){
        if(top==-1)
            cout<<"empty stack"<<endl;
        else    
            return arr[top];
    }
};

int main(){
    Stack s(5);
    s.push(100);
    s.push(100);
    s.push(123);
    cout<<s.peak()<<endl;
    s.pop();
    cout<<s.peak()<<endl;

    return 0;
}