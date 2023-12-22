/*
struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }
        
};
*/
class Solution
{
    public:
    Node* reverseDLL(Node * head)
    {
        //Your code here
        Node* prev = NULL;
        Node* curr = head;
        Node* temp;
    
        while(curr){
            temp = curr->next;
            curr->next = prev;
            curr->prev = temp;
            prev = curr;
            curr = temp;
        }
    
        return prev;

    }
};
