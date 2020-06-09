/*  O(N) and O(1) solution 
    Idea: Create the copy of node 1 and insert it between node 1 & node 2 in original Linked List and similarly do it for all the remaining node.
    Now adjust the random pointers in newly created node, which can be set by 
    original->next->random = original->random->next where original->next is our clone copy of original node

    And now, once we have adjusted all random pointers, let's restore the original and clone copy.
    original->next = original->next->next & copy->next=copy->next->next i.e make jumps of 2 becs we've one duplicate copy.
*/

class Solution {
public:
    Node* copyRandomList(Node* head) 
    {
        if(head==NULL)
            return NULL;
        
        Node* curr = head;
            
        while(curr)     //create copy of original node, and insert it after the corresponding previous one.
        {
            Node* temp = curr->next;
            curr->next = new Node(curr->val);
            curr->next->next = temp;
            curr = temp;
        }
        
        curr = head;
        
        while(curr)     //fix the random pointers for newly created copied node
        {
            if(curr->next)
                curr->next->random = curr->random?curr->random->next:curr->random;
            
            curr = curr->next?curr->next->next:curr->next;
        }
        
        Node* original = head, *copy = head->next;
        Node* temp = copy;
        while(original && copy)     //restore the connections in both the list
        {
            original->next = original->next?original->next->next:original->next;
            copy->next = copy->next?copy->next->next:copy->next;
            
            original = original->next;
            copy = copy->next;
            
        }
        
        return temp;
        
    }
};