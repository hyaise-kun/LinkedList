#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Optimal
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *temp1 = headA;

        ListNode *temp2 = headB;

        if (headA == nullptr || headB == nullptr)
            return nullptr;

        while (temp1 != temp2)
        {

            temp1 = temp1->next;
            temp2 = temp2->next;

            if (temp1 == temp2)
                return temp1;

            if (temp1 == nullptr)
                temp1 = headB;
            if (temp2 == nullptr)
                temp2 = headA;
        }

        return temp1;
    }
};

class better
{
public:
    ListNode *collisonp(ListNode *small, ListNode *large, int z)
    {
        ListNode *temp = large;

        for (int i = 0; i < z; i++)
        {
            temp = temp->next;
        }

        while (small != temp)
        {
            small = small->next;
            temp = temp->next;
        }

        return small;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *temp1 = headA;

        ListNode *temp2 = headB;

        int n1 = 0, n2 = 0;

        while (temp1 != nullptr)
        {
            n1++;
            temp1 = temp1->next;
        }

        while (temp2 != nullptr)
        {
            n2++;
            temp2 = temp2->next;
        }

        if (n1 < n2)
        {

            return collisonp(headA, headB, n2 - n1);
        }

        else
        {

            return collisonp(headB, headA, n1 - n2);
        }

        return nullptr;
    }
};




// brute force 
class brute
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        unordered_map<ListNode *, int> mpp;
        ListNode *temp1 = headA;
        ListNode *temp2 = headB;

        while (temp1 != nullptr)
        {

            mpp[temp1] = 1;

            temp1 = temp1->next;
        }

        while (temp2 != nullptr)
        {

            if (mpp.find(temp2) != mpp.end())
            {
                return temp2;
            }

            temp2 = temp2->next;
        }

        return nullptr;
    }
};

int main()
{

    return 0;
}