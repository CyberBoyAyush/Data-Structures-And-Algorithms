#include <bits/stdc++.h>
using namespace std;

// Convert Array to Linked List
class Node
{
public:
    int data; // Here we store Data

    Node *next; // This is the pointer to next node

    // Using constuctor to store data in it
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    Node(int data, auto val)
    {
        this->data = data;
        this->next = val;
    }
};

Node *convertArr2LL(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;

    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

int lengthLL(Node *&head)
{
    Node *temp = head;
    int cnt = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        cnt++;
    }
    return cnt;
}

bool isPresent(Node *&head, int val)
{
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == val)
            return 1;
        temp = temp->next;
    }
    return 0;
}

void printLL(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node *removeHead(Node *head)
{
    // edge case
    if (head == NULL)
        return head;
    Node *temp = head;
    head = head->next;
    delete temp;
    return head;
}

Node *removeTail(Node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }

    Node *temp = head;

    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = NULL;
    return head;
}

Node *removeK(Node *&head, int k)
{
    if (head == NULL)
    {
        return head;
    }

    if (k == 1)
    {
        Node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    int cnt = 0;
    Node *temp = head;
    Node *prev = NULL;
    while (temp != NULL)
    {
        cnt++;
        if (cnt == k)
        {
            prev->next = prev->next->next;
            free(temp);
            break;
        }

        prev = temp;
        temp = temp->next;
    }
    return head;
}

Node *removeEl(Node *&head, int el)
{
    if (head == NULL)
    {
        return head;
    }

    if (head->data == el)
    {
        Node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    Node *temp = head;
    Node *prev = NULL;
    while (temp != NULL)
    {
        if (temp->data == el)
        {
            prev->next = prev->next->next;
            free(temp);
            break;
        }

        prev = temp;
        temp = temp->next;
    }
    return head;
}

Node *insertHead(Node *head, int val)
{
    Node *temp = new Node(val, head);
    return temp;
}

Node *insertTail(Node *head, int val)
{
    if (head == NULL)
    {
        return new Node(val);
    }

    Node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    Node *newNode = new Node(val);
    temp->next = newNode;
    return head;
}

Node *inseertKPos(Node *head, int el, int k)
{
    if (head == nullptr)
    {
        if (k == 1)
        {
            return new Node(el);
        }
    }

    if (k == 1)
    {
        return new Node(el);
    }

    int cnt = 0;
    Node *temp = head;
    while (temp != nullptr)
    {
        cnt++;
        if (cnt == k - 1)
        {
            Node *x = new Node(el, temp->next);
            temp->next = x;
            break;
        }
        temp = temp->next;
    }

    return head;
}

Node *insertBeforeValue(Node *head, int el, int val)
{
    if (head == nullptr)
    {
        return NULL;
    }

    if (head->data == val)
    {
        return new Node(el);
    }

    Node *temp = head;
    while (temp->next != nullptr)
    {
        if (temp->next->data == val)
        {
            Node *x = new Node(el, temp->next);
            temp->next = x;
            break;
        }
        temp = temp->next;
    }

    return head;
}

int main()
{
    vector<int> arr = {2, 3, 4, 5, 6};
    Node *head = convertArr2LL(arr);
    // cout<< head->data<<endl;

    // // Traverse In LL
    // Node* temp = head;
    // while(temp!=NULL){
    //     cout<< temp->data<<" ";
    //     temp= temp->next;
    // } cout<<endl;

    // Length of LL
    // cout<< lengthLL(head);

    // cout<<endl;
    // Search in LL
    // cout<<isPresent(head,2);

    /*
    //Remove Head
    head = removeHead(head);
    cout<<"Removing Head"<<endl;
    printLL(head);
    */

    /*
    //Remove Tail
    head = removeTail(head);
    printLL(head);
    */

    //    printLL(head);
    //    // Remove Kth Element
    //    head = removeK(head,1);
    //    printLL(head);

    //    // Remove El
    //    head = removeEl(head,6);
    //    printLL(head);

    // // Insert at head
    // head = insertHead(head,100);
    // printLL(head);

    // // Insert at tail
    // head = insertTail(head,100);
    // printLL(head);

    // // Insert at k pos
    // head = inseertKPos(head,100,4);
    // printLL(head);

    // Insert Before Value
    head = insertBeforeValue(head, 100, 4);
    printLL(head);
}