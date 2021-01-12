/* 
    Give a multi level DLL, flatten that into a single level DLL.
    TC: O(N) & Space: O(1)
*/

class Solution {
public:
    Node* flatten(Node* head) 
    {
        Node *p = head;
        while(p)
        {
            if(p->child)   // When there's a child of this node then adjust pointers to connect (p and p->child) and traverse the children to connect the last node next to p->next
            {
                Node *temp = p->next;
                p->next = p->child;
                p->next->prev = p;
                p->child = NULL;
                
                // Traverse till the end of this level
                Node *runner = p->next;
                while(runner && runner->next)
                    runner = runner->next;
                
                runner->next = temp;
                if(temp)
                    temp->prev = runner;
            }
            p = p->next;
        }
        return head;
    }
};