/* 
    Given a LL and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x. Preserving the original relative order of nodes.
    
    Example:  [1,4,3,2,1,5,2], x = 3  => [1,2,1,2,4,3,5]

    Idea: is to seperate the LL into two list first containing all the nodes which are less than X and other containing nodes that are >= X. And link them afterwards.
    TC: O(N) & Space: O(1)
*/

ListNode *partition(ListNode *head, int x)
{
    if (!head)
        return NULL;

    ListNode *beforeHead = new ListNode(0), *afterHead = new ListNode(0);
    ListNode *before = beforeHead, *after = afterHead;

    while (head != NULL)
    {
        if (head->val < x)
        {
            before->next = head;
            before = before->next;
        }
        else
        {
            after->next = head;
            after = after->next;
        }
        head = head->next;
    }
    after->next = NULL; // close the other end of list becz last after element need not to be the last element of the original LL
    before->next = afterHead->next;
    return beforeHead->next;
}