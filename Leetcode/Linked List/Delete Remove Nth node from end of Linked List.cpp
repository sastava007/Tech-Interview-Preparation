/*  We've to do this in a single pass, i.e without calculating the length of list first. We can use 2 pointers (fast & slow) such that they're at difference of N nodes 
    TC: O(N) and Space: O(1)
*/

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