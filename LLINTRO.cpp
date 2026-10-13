#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

struct Node
{
    int data;
    Node *next;
};

int main()
{

    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    int n = v.size();

    Node *head = new Node();
    head->data = v[0];

    Node *mover = head;

    for (int i = 1; i < n; i++)
    {
        Node *temp = new Node();
        temp->data = v[i];
        mover->next = temp;
        mover = temp;
    }

    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}