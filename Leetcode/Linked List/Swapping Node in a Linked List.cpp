/* 
    The learning that we can make from this ques is how to solve problems requiring 2 pointers in a single traversal by making use of the search performed so far
    and without starting the search from head again.

    Idea is to just perform a single traversal and as soon as we get first pointer, start looking for second pointer right after using fast = p1->next
 */

ListNode *swapNodes(ListNode *head, int k)
{
    ListNode *p1 = head;
    for (int i = 1; i < k; i++)
        p1 = p1->next;

    ListNode *slow = head, *fast = p1->next;

    while (fast)
    {
        fast = fast->next;
        slow = slow->next;
    }

    swap(slow->val, p1->val);
    return head;
}