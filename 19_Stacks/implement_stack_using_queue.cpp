#include<bits/stdc++.h>
using namespace std;
class MyStack {
public:
    MyStack() {
        
    }
    queue<int> q1;
    queue<int> q2;

    
    bool empty() {
        return q1.empty() && q2.empty();
    }

    void push(int x) {
        // agar dono khali hai
        if(empty()){
            q1.push(x); // or q2.push(x);
        }
        else if(q1.empty()){
            q2.push(x);
        }
        else{
            q1.push(x);
        }
    }
    
    int pop() {
        if(empty()){
            return -1;
        }
        else if(q1.empty()){
            while(q2.size()>1){
                q1.push(q2.front());
                q2.pop();
            }
            int el = q2.front();
            q2.pop();
            return el;
        }
        else{
            while(q1.size()>1){
                q2.push(q1.front());
                q1.pop();
            }
            int el = q1.front();
            q1.pop();
            return el;
        }
    }
    
    int top() {
        if(empty()){
            return -1;
        }
        else if(q1.empty()){
            return q2.back();
        }
        else{
            return q1.back();
        }
    }
    
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
int main(){
 
return 0;
}