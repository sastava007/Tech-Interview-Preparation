/* 
    Given a singly linked list find whether isPalindrome is
    Idea:
        1. First find the middle point of linked list (call it slow*)
        2. Now reverse the second half of linekd list and start comparing each node by node.

    TC: O(N) and Space: O(1)
*/

ListNode *reverse(ListNode *head)
{
    ListNode *prev = NULL;
    while (head)
    {
        ListNode *temp = head->next;
        head->next = prev;
        prev = head;
        head = temp;
    }
    return prev;
}
bool isPalindrome(ListNode *head)
{
    if (!head)
        return true;

    // 1. Find the second middle node of linked list
    ListNode *slow = head, *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // 2. Now reverse the second half of linked list i.e slow->next

    ListNode *head2 = reverse(slow);

    while (head != slow && head2)
    {
        if (head->val != head2->val)
            return false;

        head = head->next;
        head2 = head2->next;
    }

    return true;
}