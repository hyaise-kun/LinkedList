
 struct ListNode {
     int val;
     ListNode *next;
      ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
ListNode* rev(ListNode* head) {

    if (head == nullptr || head->next == nullptr)
        return head;

    ListNode* newNode = rev(head->next);

    ListNode* front = head->next;

    front->next = head;
    head->next = nullptr;

    return newNode;
}

class Solution {
public:
    bool isPalindrome(ListNode* head) {

        ListNode* temp = head;

        ListNode* head2 = new ListNode();

        ListNode* temp2 = head2;

        while (temp != nullptr) {
            temp2->next = new ListNode(temp->val);
            temp2 = temp2->next;

            temp = temp->next;
        }


temp = head;

head2->next = rev(head2->next) ; 


        while (temp != nullptr) {

            if (temp->val != head2->next->val)
                return false;

            temp = temp->next;
            head2 = head2->next;
        }

        return true;
    }
};

int main ( ) {
    
}