/*  We've to do this in a single pass, i.e without calculating the length of list first. We can use 2 pointers (fast & slow) such that they're at diff of N nodes 
    TC: O(N) and Space: O(1)
*/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        if(head==NULL)
            return NULL;
        
        ListNode* dummy = new ListNode(0);  // create a dummy node, to avoid the case when we've to delete our head node itself
        dummy->next = head;
        
        ListNode *slow = dummy, *fast = dummy;
        for(int i=0; i<n; i++)      // move the fast pointer N step ahead then slow pointer
            fast = fast->next;
        
        while(fast->next)   // now, move this equally at a time
        {
            fast = fast->next;
            slow = slow->next;
        }
        
        ListNode *temp = slow->next;
        slow->next = slow->next->next;
        
        delete temp;        // free the memory by deleting the node
        
        return dummy->next;
    }
};