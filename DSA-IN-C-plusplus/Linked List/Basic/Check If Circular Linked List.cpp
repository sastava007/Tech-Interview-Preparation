

/* Link list Node 
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
}; 
*/

/* Should return true if linked list is circular, else false */
bool isCircular(Node *head)
{
   // Your code here
   Node* temp = head;
   
   while(temp){
       temp = temp->next;
       if(temp == head) return 1;
   }
   
   return 0;
}
