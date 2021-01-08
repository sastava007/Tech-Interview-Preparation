/* 
    Find whether there exists a cycle in linked list or not.
    One way is to strore the nodes in a hash-set and check whether the current node already exists in it or not.

    But we can solve this in constant space using 2 pointers(fast & slow). The fast pointer moves at twice speed and will eventually meet the slower one.
    
    TC: O(N) if no cycle & O(N+K) if cycle where K is length of cycle

*/

class Solution 
{
public:
    bool hasCycle(ListNode *head) 
    {
        if(!head || !head->next)
            return false;
        
        ListNode* slow = head, *fast = head->next;
        
        while(fast && fast->next)
        {
            if(slow == fast)    // In case of cycle and loop always compares both the node and their value
                return true;
            
            slow = slow->next;
            fast = fast->next->next;
        }
        return false;
        
        /* 
            ListNode slow = head;
            ListNode fast = head.next;
            while (slow != fast) {
                if (fast == null || fast.next == null) {
                    return false;
                }
                slow = slow.next;
                fast = fast.next.next;
            }
            return true; 
        */
    }
};

/*  Find the entry point of loop using Floyd's Cycle Detection Algo 
    Let L1 be the distance b/w (head & entry) point, L2 be the distance b/w entry point & meeting point
    And C is defined a length of Cycle.

    dist(fast) = 2*dist(slow)
    L1+nC+L2 = 2(L1 + L2)  => L1+l2 = nC => L1 = nC-L2
    And during second time L1 = C-L2

    So both of them here are same
*/
ListNode *detectCycle(ListNode *head) 
{
    if(!head || !head->next)
        return NULL;
    
    ListNode *slow = head, *fast = head;
    
    while(fast!=NULL && fast->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    
        if(slow == fast)    // if cycle exists, then reset the slow pointer from the starting
        {
            slow = head;
            while(slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return NULL;
}