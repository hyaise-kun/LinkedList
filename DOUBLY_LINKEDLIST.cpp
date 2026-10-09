#include <bits/stdc++.h>
using namespace std;

struct Node
{

    int data;
    Node *next;

    Node *back;

    Node(int d, Node *a, Node *b)
    {

        data = d;
        next = a;
        back = b;
    }

    Node(int d)
    {

        data = d;
        next = nullptr;
        back = nullptr;
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

int SIZEOFLL(Node *head)
{
    int cnt = 0;
    Node *temp = head;

    while (temp != nullptr)
    {

        cnt++;
        temp = temp->next;
    }

    return cnt;
}

Node *killbyhead(Node *head)
{

    Node *temp = head;
    head = head->next;
    head->back = nullptr;
    temp->next = nullptr;
    delete temp;
    return head;
}

Node *killbyTAil(Node *head)
{

    Node *temp = head;
    Node *Prev = temp;
    if (temp == nullptr || temp->next == nullptr)
    {
        return nullptr;
    }

    while (temp->next != nullptr)
    {
        Prev = temp;
        temp = temp->next;
    }

    Prev->next = nullptr;
    temp->back = nullptr;

    delete temp;
    return head;
}

Node *killAnyone(Node *head, int k)
{
    int cnt = 0;

    if (k == 1)
    {

        head = killbyhead(head);
        return head;
    }

    if (k == SIZEOFLL(head))
    {
        head = killbyTAil(head);
        return head;
    }

    Node *temp = head;
    while (temp->next != nullptr)
    {
        cnt++;

        if (cnt == k)
        {

            temp->back->next = temp->next;
            temp->next->back = temp->back;
            temp->back = nullptr;
            temp->next = nullptr;
            delete temp;
          break ; 
        }

        temp=temp->next;
    }

    return head; 

}

Node* InsertionBeforeHead ( Node* head  , int value ){

Node * temp = new Node( value , head , nullptr);
head->back=temp;
head= temp; 
return head;

}

Node* InsertionBeforeTail ( Node* head  , int value ){

Node * temp = new Node( value );



        Node* mover = head ; 


        if( head->next==nullptr){
            head = InsertionBeforeHead(head , value); 
            return head ; 
        }
    




         Node * prev = mover ; 
        while (mover->next!=nullptr)
        {
             prev = mover ; 
            mover= mover->next;
        }
temp->next= mover; 
temp->back=prev;
prev->next= temp ; 
mover->back=temp ; 


return head ; 

        

}

Node* InsertionAtplace ( Node* head , int value , int k ){
        int cnt = 0 ; 

        Node* temp = head ; 

        if( k<1 || k >SIZEOFLL(head)) return head ; 

    if( k==1){
        head = InsertionBeforeHead(head ,value);
        return head ; 
    }
    if( k==SIZEOFLL(head)) {
        head = InsertionBeforeTail( head , value);
        return head ; 
    }






    while ( temp->next!=nullptr)
    {
        cnt++;
      
            if( cnt ==k ) break; 
             temp= temp->next;
    }

Node* newnode = new Node( value, temp , temp->back);

temp->back->next= newnode; 
temp->back= newnode; 


return head ; 








}

int main()
{
    vector<int> v = {1, 2, 3,4, 6,  8};
    int n = v.size();

    Node *head = new Node(v[0]);
    Node *prev = head;
    for (int i = 1; i < n; i++)
    {
        Node *temp = new Node(v[i]);
        temp->back = prev;
        prev->next = temp;
        prev = temp;
    }

    head = InsertionAtplace(head ,5 ,7);
    print(head);

    return 0;
}