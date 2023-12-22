

/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

//Function to insert a node in the middle of the linked list.
Node* insertInMiddle(Node* head, int x)
{
	// Code here
	Node *temp = new Node(x);
	Node *slow = head, *fast = head;
	
	while(fast->next != NULL && fast->next->next != NULL){
	    slow = slow->next;
	    fast = fast->next->next;
	}
	
	temp->next = slow->next;
	slow->next = temp;
	return head;
}
