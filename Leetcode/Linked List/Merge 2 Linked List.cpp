/* Merge 2 sorted linked list */

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
    {
        if(!l1)
            return l2;
        if(!l2)
            return l1;
        
        ListNode dummy(0);
        ListNode *p = &dummy;
        
        while(l1 && l2)
        {
            if(l1->val < l2->val)
            {
                p->next = l1;
                l1 = l1->next;
            }
            else
            {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        
        if(l1)
            p->next = l1;
        if(l2)
            p->next = l2;
        
        return dummy.next;
    }
};