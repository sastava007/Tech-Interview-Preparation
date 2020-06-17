/*  First find the middle of list using slow & fast pointers.
    Then reverse the second half, i.e after the slow->next
    And then in last, merge both of them.

    TC: O(N) and O(1) Space
*/

class Solution {
public:
    void reorderList(ListNode* head) 
    {
        if(head==NULL || head->next==NULL)
            return;

        ListNode* slow = head;
        ListNode* fast = head->next;   
        // find the middle node, which will be slow
        while(fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        
        ListNode* head2 = reverse(slow->next);  //reverse the second half;
        slow->next=NULL;
        merge(head, head2);     //merge the two heads
    }
    
private:
    ListNode* reverse(ListNode* node)
    {
        ListNode* prev=NULL;
        while(node)
        {
            ListNode* temp = node->next;
            node->next=prev;
            prev=node;
            
            node = temp;
        }
        return prev;
    }
    void merge(ListNode* head, ListNode* head2)
    {
        while(head && head2)
        {
            ListNode* tmp1 = head->next;
            ListNode* tmp2 = head2->next;
            
            head2->next = head->next;
            head->next = head2;
            head = tmp1;
            head2 = tmp2;           
        }
    }
};