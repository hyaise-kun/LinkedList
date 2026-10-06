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

Node *killforhead(Node *head)
{

    Node *temp = head;
    head = head->next;
    delete temp;
    return head;
}

Node *killforTail(Node *head)
{

    Node *temp = head;

    if (head == nullptr || head->next == nullptr)
    {
        return nullptr;
    }

    while (temp->next->next != nullptr)
    {

        temp = temp->next;
    }

    delete temp->next;

    temp->next = nullptr;

    return head;
}

Node *killforALL(Node *head, int k)
{
    // 1 2 3 4 5
    Node *temp = head;

    Node *prev = nullptr;
    int cnt = 0;
    if (head == nullptr || head->next == nullptr)
    {
        return nullptr;
    }

    if (k == 1)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    if (k == 5)
    {

        while (temp->next->next != nullptr)
        {

            temp = temp->next;
        }

        delete temp->next;

        temp->next = nullptr;

        return head;
    }

    while (temp->next != nullptr)
    {

        cnt++;

        if (cnt == k)
        {

            // temp -> kth element and prev-> k-1
            prev->next = temp->next;
            delete temp;

            break;
        }

        prev = temp;
        temp = temp->next;
    }
    return head;
}

int main()
{

    vector<int> v = {1, 23, 32, 45, 56};

    int n = v.size();

    Node *head = new Node(v[0]);
    Node *mover = head;

    for (int i = 1; i < n; i++)
    {
        Node *temp = new Node(v[i]);
        mover->next = temp;
        mover = temp;
    }
    head = killforALL(head, 8);
    print(head);

    return 0;
}