#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        vector<int> v;

        ListNode *temp = head;
        ListNode *temp2 = head;

        while (temp->next != nullptr)
        {
            v.push_back(temp->val);
            temp = temp->next;
        }

        int i = 0;
        while (temp2->next != nullptr)
        {
            temp->val = v[i];
            i++;
            temp = temp->next;
        }

        return head;
    }
};

ListNode *optimalreverse(ListNode *head)
{

    if (head == nullptr || head->next == nullptr)
        return head;

    ListNode *last = nullptr;
    ListNode *temp = head;
    ListNode *front = nullptr;

    while (temp != nullptr)
    {
        front = temp->next;

        temp->next = last;

        last = temp;

        temp = front;
    }

    return last;
}


ListNode *reCursion(ListNode *head)
{

    if (head == nullptr || head->next == nullptr)
        return head;

    ListNode *newnode = reCursion(head->next);
    ListNode *front = head->next;

    front->next = head;

    head->next = nullptr;

    return newnode;
}




int main()
{
}