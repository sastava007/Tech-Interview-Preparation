/* 
    Given a linked list, rotate the list to the right by k places. K can be >= length of list as well  as

    The basic idea is to link the tail of the list with the head, make it a cycle. Then count to the rotate point and cut it from there and make point head
    to the next of curr i.e curr->next and later close the that end with NULL.

    To count the rotate point use formula newPoint = N - K % N

*/

class Solution 
{
public:
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if(!head || !head->next)
            return head;
        
        ListNode *curr = head;
        int n = 1;
        
        while(curr->next)
        {
            curr = curr->next;
            n++;
        }
        curr->next = head;     // connect the last node with head as anyways after rotation it need to be connected
        k = n-k%n;  // rotate point
        
        while(k--)      // Here we're directly looping from i=0 to i<k instead of normally starting from 1 when we don't have any dummy or 1 extra node as we have here
            curr = curr->next;
        
        head = curr->next;
        curr->next = NULL;
        return head;
    }
};