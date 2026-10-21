// i wanna kms and do nothing .
// not today
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

void ConvertArraytoLL(vector<int> &nums, Node *head)
{
    int n = nums.size();
    Node *temp = head;
    for (int i = 1; i < n; i++)
    {
        Node *mover = new Node(nums[i]);
        temp->next = mover;
        temp = mover;
    }
}

Node *Steins_Gate(Node *head)
{

    if (head == nullptr || head->next == nullptr)
        return head;
    int one = 0;
    int zero = 0;
    int two = 0;

    Node *temp = head;
    while (temp != nullptr)
    {
        if (temp->data == 0)
            zero++;
        if (temp->data == 1)
            one++;
        if (temp->data == 2)
            two++;

        temp = temp->next;
    }
    Node *hello = head;
    while (hello != nullptr)
    {
        if (zero)
        {
            hello->data = 0;
            zero--;
        }
        else if (one)
        {
            hello->data = 1;
            one--;
        }
        else if (two)
        {
            hello->data = 2;
            two--;
        }

        hello = hello->next;
    }

    return head;
}

Node *sorting_102(Node *head)
{

    if (head == nullptr || head->next == nullptr)
        return head;

    Node *zerohead = new Node(-1);
    Node *onehead = new Node(-1);
    Node *twohead = new Node(-1);

    Node *zero = zerohead;
    Node *one = onehead;
    Node *two = twohead;

    Node *temp = head;

    while (temp != nullptr)
    {
        if (temp->data == 0)
        {
            zero->next = temp;
            zero = zero->next;
        }

        if (temp->data == 1)
        {
            one->next = temp;
            one = one->next;
        }

        if (temp->data == 2)
        {
            two->next = temp;
            two = two->next;
        }

        temp = temp->next;
    }

    if (onehead->next != nullptr)
    {
        zero->next = onehead->next;
        one->next = twohead->next;
    }

    else
    {
        zero->next = twohead->next;
    }
    two->next = nullptr;

    Node *ans = zerohead->next;
    delete zerohead;
    delete onehead;
    delete twohead;

    return ans;
}

int main()
{

    {
        {
            {
                {
                    {
                        {
                            {
                                {
                                    {
                                        {
                                            vector<int> nums = {1, 0, 2, 0, 0, 0, 2, 2, 2, 1, 1, 1};
                                            Node *head = new Node(nums[0], nullptr);
                                            ConvertArraytoLL(nums, head);
                                            head = sorting_102(head);
                                            print(head);
                                            {
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}
