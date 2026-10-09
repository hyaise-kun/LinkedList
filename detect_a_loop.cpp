#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class brute
{
public:
    bool isThisALoop(ListNode *head)
    {

        unordered_map<ListNode *, int> mpp;

        ListNode *temp = head;

        while (temp != nullptr)
        {
            if (mpp.find(temp) != mpp.end())
                return true;
            mpp[temp]++;
            temp = temp->next;
        }

        return false;
    }
};

class optimal
{
public:
    bool isThisALoop2(ListNode *head)
    {

        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (fast == slow)
                return true;
        }

        return false;
    }
};
int main()
{

    return 0;
}