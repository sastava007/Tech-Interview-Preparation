/* Given a singly linked list, group all odd nodes together followed by the even nodes. Here odd & even means linked list no. and not value of node */

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) 
    {
        if(head==NULL)
            return head;
        
        ListNode *odd = head, *evenhead = head->next, *even = evenhead;
        
        while(even && even->next)
        {
            odd->next = odd->next->next;
            even->next = even->next->next;
            
            odd = odd->next;
            even = even->next;
            
        }
        odd->next = evenhead;
        
        return head;
    }
};