/*  
    Concept of Slow and Fast pointers to find the middle of linked lists
    Each time, slow go 1 steps while fast go 2 steps. When fast arrives at the end, slow will arrive right in the middle.
*/

class Solution {
public:
    ListNode* middleNode(ListNode* head) 
    {
        ListNode *slow = head, *fast = head;
        
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
};