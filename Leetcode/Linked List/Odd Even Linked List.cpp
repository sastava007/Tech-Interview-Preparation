/* Given a singly linked list, group all odd nodes together followed by the even nodes. Here odd & even means linked list no. and not value of node 

    Input: 1->2->3->4->5->NULL
    Output: 1->3->5->2->4->NULL

    Input: 2->1->3->5->6->4->7->NULL
    Output: 2->3->6->7->1->5->4->NULL

    TC: O(N)  & Space: O(1)
*/

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