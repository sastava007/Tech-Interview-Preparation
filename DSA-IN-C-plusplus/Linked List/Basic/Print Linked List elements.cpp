//Recursive:

void display( Node* head ) {
    if ( !head ) return;
    cout << head->data << ' ';
    display( head->next );
} 


// Iterative

class Solution
{
    public:
    void display(Node *head)
    {
      //your code goes here
      while(head){
          cout<<head->data<<" ";
          head = head->next;
      }
    }
}
