#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;

    Node(int d)
    {
        data = d;
        next = nullptr;
    }

    Node(int d, Node *ptr)
    {
        data = d;
        next = ptr;
    }
};

void print(Node *head)
{

    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}


int SIZEOFLL(Node* head ){
    int  cnt = 0 ; 
    Node* temp = head; 


    while ( temp!=nullptr){

        cnt++;
        temp = temp->next;
    }

    return cnt ; 
}

Node *insertionbyhead(Node *head, int value)
{
    Node *temp = new Node(value, head);

    temp->next = head;
    return temp;
}

Node *insertionbyTail(Node *head, int value)
{
    Node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    Node *newtry = new Node(value);
    temp->next = newtry;

    return head;
}

Node *insertionbyALL(Node *head, int k, int value)
{
    int cnt = 0;
    Node *temp = head;
    if (k == 1)
    {
        // Node *temp = new Node(value, head);

        // temp->next = head;
        return new Node(value, head);
    }

    if (k == SIZEOFLL(head)+1)
    {
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }

        Node *newtry = new Node(value);
        temp->next = newtry;

        return head;
    }

    while (temp->next != nullptr)
    {

        cnt++;

        if (cnt == k - 1)
        {
            Node *newtry = new Node(value, temp->next);
            temp->next = newtry;
            break;
        }

        temp = temp->next;
    }

    return head;
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};

    int n = v.size();

    Node *head = new Node(v[0]);
    Node *mover = head;

    for (int i = 1; i < n; i++)
    {
        Node *temp = new Node(v[i]);
        mover->next = temp;
        mover = temp;
    }

    head = insertionbyALL(head, 5, 3);
    print(head);
    return 0;
}