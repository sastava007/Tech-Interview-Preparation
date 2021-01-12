/* 
    Given a linked list, swap every two adjacent nodes and return its head.
    Example:
        [1->2->3->4] => [2->1->4->3]
        [1->2->3->4->5] => [2->1->4->3->5]
    
    Tricky: Make sure to adjust the previous pointers, like after swapping 1->2 => 2->1 and after swapping 3->4 => 4->3. So we also need to adjust the pointers between 1 & 3
    And as in this case also the head pointer would get affected in the process, so that's why using a dummy node. 
*/

/* TC: O(N) and Space: O(1)*/

ListNode *swapPairs(ListNode *head)
{
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *prev = dummy;

    while (prev->next && prev->next->next)
    {
        ListNode *secondNode = prev->next->next, *temp = secondNode->next; // *firstNode = prev->next for clear understanding

        secondNode->next = prev->next;
        prev->next->next = temp;
        prev->next = secondNode;

        prev = prev->next->next;
    }

    return dummy->next;
}

/* Using recusion TC: O(N) and Space: O(N) */
ListNode *swapPairs(ListNode *head)
{
    //base case here
    if (!head || !head->next)
        return head;

    // Swap first two nodes and recurse for the remaining
    ListNode *temp = head->next;
    head->next = swapPairs(temp->next);     // head->next would point to the node returned from the recursive call ex for 1->2->3->4  1->next = swapPairs(3) which is 4
    temp->next = head;

    return temp;    // return the head node of this swap operation
}
