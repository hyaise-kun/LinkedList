#include <bits/stdc++.h>
using namespace std;
struct Node
{

    int data;
    Node *next;

    Node *back;

    Node(int d, Node *a, Node *b)
    {

        data = d;
        next = a;
        back = b;
    }

    Node(int d)
    {

        data = d;
        next = nullptr;
        back = nullptr;
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

int SIZEOFLL(Node *head)
{
    int cnt = 0;
    Node *temp = head;

    while (temp != nullptr)
    {

        cnt++;
        temp = temp->next;
    }

    return cnt;
}

Node *reversing(Node *head)
{
    Node *temp = head;
Node* holder = nullptr;
    while (temp != nullptr)
    {

       holder = temp->back;
        temp->back = temp->next;
        temp->next = holder;

        temp = temp->back;
    }
  return holder->back ; 
}

int main()
{

    vector<int> v = {1, 2, 3, 4, 6, 8};
    int n = v.size();

    Node *head = new Node(v[0]);
    Node *prev = head;
    for (int i = 1; i < n; i++)
    {
        Node *temp = new Node(v[i]);
        temp->back = prev;
        prev->next = temp;
        prev = temp;
    }

head = reversing( head);
    print(head ); 

    return 0;
}