/* 
    Delete all the instances of node with value = val 

    Edge Case: When there are continious such elemenets like 1->2->6->6->4 and we need to delete to 6
        OR when we need to delete the first element of list itself in that case we need a dummy node preceeding it.

    TC: O(n) and Space: O(1)
*/

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) 
    {   
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode *p = dummy;
        
        while(p && p->next)
        {
            if(p->next->val == val)
            {
                ListNode *temp = p->next;
                p->next = p->next->next;
                delete(temp);
            }
            else
                p = p->next;
        }
        return dummy.next;
    }
};