/* 
    Given two linked lists: list1 and list2, remove list1's nodes from the ath node to the bth node, and put list2 in their place.
    Here 'a' and 'b' are node index and not value.

    list1 = [0,1,2,3,4,5,6], a = 2, b = 5, list2 = [1000000,1000001,1000002,1000003,1000004]
    Output: [0,1,1000000,1000001,1000002,1000003,1000004,6]

    Idea: The next node of the (a-1)th node of list1 be the 0-th node in list 2 and last node of list2 should points to the (b+1)th node. 
*/

class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) 
    {
        ListNode *start = list1;
        int i;
        for(i=0; i<a-1; i++)
            start = start->next;
        
        ListNode* end = start;
        for(; i<b; i++)
            end = end->next;
        
        start->next = list2;
        
        while(list2->next != NULL)
            list2 = list2->next;
        
        list2->next = end->next;
        return list1;
    }
};