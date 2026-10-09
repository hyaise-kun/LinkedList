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
    int lengthOfLoop(ListNode *head)
    {

        unordered_map<ListNode *, int> mpp;

        ListNode *temp = head;
        int cnt = 0;

        while (temp != nullptr)
        {

            mpp[temp]++;
            if (mpp[temp] == 3)
                break;

            if (mpp[temp] == 2)
                cnt++;

            temp = temp->next;
        }

        return cnt;
    }
};

class optimal
{
public:
    int lengthOFLL(ListNode *s, ListNode *f)
    {

        ListNode *temp = s;
        int cnt = 1;

        temp = temp->next;
        while (temp != f)
        {
            cnt++;
            temp = temp->next;
        }

        return cnt;
    }

    int findLengthOfLoop(ListNode *head)
    {

        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow)
            {
                return lengthOFLL(slow, fast);
            }
        }

        return 0;
    }
};
int main()
{

    return 0;
}