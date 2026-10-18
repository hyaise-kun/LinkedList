

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int SIZEOFLL(ListNode *head)
{
    int cnt = 0;
    ListNode *temp = head;

    while (temp != nullptr)
    {

        cnt++;
        temp = temp->next;
    }

    return cnt;
}

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {

        // if (head == nullptr)
        //     return head;

        // int target = SIZEOFLL(head) - n + 1;
        // int cnt = 0;
        // ListNode *last = nullptr;
        // ListNode *temp = head;

        // if (target == 1)
        // {
        //     // delete head
        //     if (head->next == nullptr)
        //     {
        //         return nullptr;
        //     }

        //     ListNode *mover = head;
        //     head = head->next;
        //     delete mover;

        //     return head;
        // }
        // while (temp != nullptr)
        // {
        //     cnt++;

        //     if (cnt == target)
        //     {
        //         last->next = temp->next;
        //          delete temp ; 
        //         return head;
        //     }

        //     last = temp;
        //     temp = temp->next;
        // }

        // return head;

ListNode* fast = head ; 
ListNode* slow = head ; 
for (int  i = 0; i < n; i++)
{
        fast = fast->next ; 
}
if( fast==nullptr) return head->next; 
while( fast->next!=nullptr){
    slow=slow->next; 
   fast =  fast->next;


}


ListNode* dle = slow->next; 



slow->next= slow->next->next; 

delete dle ; 


return head ; 




    }
};

#include <bits/stdc++.h>
using namespace std;

int main()
{










    
    return 0;
}