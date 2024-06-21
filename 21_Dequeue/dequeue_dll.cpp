#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next, *prev;

    Node(int x)
    {
        data = x;
    }
};

class Dequeue
{
    Node *front, *rear;

public:
    Dequeue()
    {
        front = rear = nullptr;
    }

    // push front
    void push_front(int x)
    {
        if (front == nullptr)
        {
            front = rear = new Node(x);
        }
        else
        {
            Node *temp = new Node(x);
            front->prev = temp;
            temp->next = front;
            front = temp;
        }
    }

    // push back
    void push_back(int x)
    {
        // empty
        if (front == nullptr)
        {
            front = rear = new Node(x);
        }
        else
        {
            Node *temp = new Node(x);
            rear->next = temp;
            temp->prev = rear;
            rear = temp;
        }
    }

    // pop front
    void pop_front()
    {
        // empty
        if (front == nullptr)
        {
            return;
        }
        else
        {
            Node *temp = front;
            front = front->next;
            delete (temp);
            // kya front exists krta hai
            if (front)
            {
                front->prev = nullptr;
            }
            else
            { // single node tha joh delete krdiya
                rear = nullptr;
            }
        }
    }

    // pop back
    void pop_back()
    {
        // empty
        if (front == nullptr)
        {
            return;
        }
        else
        {
            Node *temp = rear;
            rear = rear->prev;
            delete (temp);
            // kya rear exisits krta hai
            if (rear)
            {
                rear->next = nullptr;
            }
            else
            { // single node tha delete krdiya
                front = nullptr;
            }
        }
    }

    // start
    int start()
    {
        if (front == nullptr)
        {
            return -1;
        }
        else
        {
            return front->data;
        }
    }

    // end
    int end()
    {
        if (front == nullptr)
        {
            return -1;
        }
        else
        {
            return rear->data;
        }
    }
};

int main()
{
    Dequeue dq;
    dq.push_front(10);
    dq.push_front(20);
    dq.push_front(30);
    dq.push_back(30);
    dq.push_back(10);
    cout<<dq.start()<<endl;
    cout<<dq.end()<<endl;
    return 0;
}