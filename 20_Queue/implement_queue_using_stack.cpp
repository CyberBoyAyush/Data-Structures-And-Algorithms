#include<bits/stdc++.h>
using namespace std;
class MyQueue {
public:
    MyQueue() {
        
    }
    stack<int> st1; // for push operations
    stack<int> st2; // for pop operations
    bool empty() {
        return st1.empty() && st2.empty();
    }
    
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
        if(empty()){
            return -1;
        }
        else if(!st2.empty()){// stack 2 khali nahi hai
            int el = st2.top();
            st2.pop();
            return el;
        }
        else{
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
            int el = st2.top();
            st2.pop();
            return el;
        }
    }
    
    int peek() {
        if(empty()){
            return -1;
        }

        else if(!st2.empty()){
            return st2.top();
        }
        
        else{
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
            return st2.top();
        }
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
int main(){
 
return 0;
}