/*  */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        if(head==NULL)
            return NULL;
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode *slow = dummy, *fast = dummy;

        while(n--)
            fast = fast->next;
        
        while(fast->next)
        {
            fast = fast->next;
            slow = slow->next;
        }
        
        ListNode *temp = slow->next;
        slow->next = slow->next->next;
        
        delete temp;
        
        return dummy->next;
    }
};