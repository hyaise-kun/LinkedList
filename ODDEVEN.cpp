// memories are what makes us .
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

    Node(int d, Node *track)
    {
        data = d;
        next = track;
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

Node *OddEvenSelection(Node *head)
{
if( head==nullptr|| head->next==nullptr) return head ; 

    Node *odd = head;
    Node *even = head->next;
    Node *evenhead = even;

    while (even != nullptr && even->next != nullptr)
    {

        odd->next = even->next;
        odd = odd->next;

        even->next = odd->next;
        even = even->next;
    }

    odd->next = evenhead;

    return head;
}

int main()
{

    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    int n = nums.size();

    Node *head = new Node(nums[0], nullptr);

    Node *temp = head;
    for (int i = 1; i < n; i++)
    {
        Node *mover = new Node(nums[i]);
        temp->next = mover;
        temp = mover;
    }
    head = OddEvenSelection(head);
    print(head);

    return 0;
}