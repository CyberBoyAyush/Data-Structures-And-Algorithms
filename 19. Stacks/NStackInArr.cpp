#include <bits/stdc++.h> 
#include<stack>
using namespace std;
class Node{
    public:
    int index;
    Node* next;

    Node(int x){
        index = x;
        next = nullptr;
    }
};

class NStack
{
public:
    // Initialize your data structure.
    int *arr;
    Node** Top;
    stack<int> st;
    NStack(int N, int S)
    {
        arr = new int[S];
        Top = new Node *[N];
        for(int i = 0; i<N;i++){
            Top[i] = nullptr;
        }

        for(int i = 0; i<S;i++){
            st.push(i);
        }
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        if(st.empty()){
            return 0;
        }

        arr[st.top()] = x;
        Node* temp = new Node(st.top());
        temp->next = Top[m-1];
        Top[m-1] = temp;
        st.pop();
        return 1;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        if(Top[m-1]==NULL){
            return -1;
        }
        st.push(Top[m-1]->index);
        int el = arr[Top[m-1]->index];
        Top[m-1] = Top[m-1]->next;
        return el;
    }
};