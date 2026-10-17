
class Node {
	public:
	int data;
	Node* next;

	Node(int x) {
		data = x;
		next = nullptr;
	}
};


Node * rev (Node* head) {
	if (head == nullptr || head->next == nullptr)
		return head ;

	Node * newNode = rev(head->next) ;

	Node * front = head->next ;
	front->next = head ;
	head->next  = nullptr ;

	return newNode ;

}

class myversion  {
	public:
	Node* addOne(Node* head) {

		head = rev (head) ;

		Node * temp = head ;
		Node * last  = nullptr ;

		int carry = 0;

		while (temp != nullptr) {

			if (temp->data != 9) {
				temp->data = temp->data + 1;

				head = rev(head) ;
				return head ;

			}

			else {

				temp->data = 0 ;

				carry = 1 ;

			}

			last = temp ; 
			temp= temp->next ; 

		}

		if (carry == 1) {

			last->next = new Node(1) ;

			head = rev(head);

			return head ;

		}

		return head  ; 

	}
};
