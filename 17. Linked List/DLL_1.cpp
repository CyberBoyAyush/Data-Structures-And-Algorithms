#include <bits/stdc++.h>
using namespace std;

// Convert Array to Linked List
class Node
{
public:
    int data; // Here we store Data

    Node *next; // This is the pointer to next node

    Node *prev;

    // Using constuctor to store data in it
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }

    Node(int data, Node* next1, Node* back1)
    {
        this->data = data;
        this->next = next1;
        this->prev = back1;
    }
};

Node* convert2DLL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i = 1;i<arr.size();i++){
        Node* temp = new Node(arr[i],NULL,prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

void printDLL(Node* &head){
    Node* temp = head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

Node* deleteHead(Node* head){
    if(head->next == nullptr || head == NULL){
        return nullptr;
    }
    Node* prev = head;
    head = head->next;
    head->prev = nullptr;
    prev->next= nullptr;
    delete prev;
    return head;
}

Node* deleteTail(Node* &head){
    if(head==nullptr||head->next==nullptr){
        return nullptr;
    }

    Node* tail = head;
    Node * p;

    while(tail->next!=NULL){
        tail = tail->next;
    }
    p = tail->prev;
    p->next = nullptr;
    tail->prev = nullptr;

    delete tail;
    return head;

}

Node* deleteKthNode(Node* &head,int k){
    if(head == nullptr){
        return nullptr;
    }

    int cnt = 0;
    Node* kNode = head;
    while(kNode!=nullptr){
        cnt++;
        if(cnt==k) break;
        kNode = kNode->next;
    }

    Node* p = kNode->prev;
    Node* f = kNode->next;

    if(p == nullptr && f==nullptr){
        return nullptr;
    } 
    else if(p== nullptr){
        // it means this is out 1st node and we need to delete head
        return deleteHead(head);
    }
    else if(f==nullptr){
        // this is our last node and we need to delete tail
        return deleteTail(head);
    }

    p->next = f;
    f->prev = p;
    kNode->prev = nullptr;
    kNode->next = nullptr;
    delete kNode;
    return head;
}

void deleteNode(Node* temp){
    Node* p= temp->prev;
    Node* f= temp->next;

    if(f==nullptr){
        // means tail
        p->next=nullptr;
        temp->prev = nullptr;
        free(temp);
    }
     p->next=f;
     p->prev = p;

     temp->next=temp->prev=nullptr;
     free(temp);
}

Node* insertBeforeHead(Node* &head, int val){
    Node * newHead = new Node(val,head,nullptr);
    head->prev = newHead;
    return newHead;
}

int main()
{
    vector<int> arr = {2, 3, 4, 5, 6};
    Node* head = convert2DLL(arr);
    printDLL(head);

//     //Delete Head
//     head = deleteHead(head);
//     printDLL(head);

//     // Delete Tail
//     head = deleteTail(head);
//     printDLL(head);

//    // Delete Kth Element
    //    head = deleteKthNode(head,2);
    //    printDLL(head);

//    //Delete Node
    //    deleteNode(head->next);
    //    printDLL(head);

      // Insert Before Head
      head = insertBeforeHead(head,10);
      printDLL(head);

}