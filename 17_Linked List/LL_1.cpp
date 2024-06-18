#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data; // Here we store Data

    Node *next; // This is the pointer to next node

    // Using constuctor to store data in it
    Node(int data){
        this-> data = data;
        this-> next = NULL;
    }
};

void insertAtHead(Node * &head, int d){
    // This will create new node with data d
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}

void printLL(Node * &head){
    Node *temp= head;
    while (temp!=NULL)
    {
        cout<< temp-> data <<" ";
        temp = temp -> next;

    } cout<<endl;
    
}

int main(){
    Node *node1 = new Node(100);

    // cout<<node1->data<<endl;
    // cout<<node1->next<<endl;

    Node *head = node1;
    printLL(head);

    insertAtHead(head,12);

    printLL(head);
}