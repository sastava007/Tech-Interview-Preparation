/*  The given head need not be the head node, it could be any possible node. So there are many cases
    1. if head is null
        create new node, and made it point to itself, make head point to newly created node and return the head node

    2. Traverse till we find the maximum node, now if (curr-val >= max-val || curr-val <= min-val) then add new node b/w maximum & minimum node
    3. Otherwise keep on traversing untill node->val < curr-val, and insert here

    Ex: 3->5->1   and  X = 4  (3->5->1 is same as 1->3->5 becz of circular nature)
    O/P:  5->1->3->4  OR 1->3->4->5

    TC: O(N)
*/


ListNode * insert(ListNode * head, int x) 
{
    if(head==nullptr)
    {
        ListNode* node = new ListNode(x);
        node->next = node;
        return node;
    }
    
    ListNode *max = head;       // find the maximum node
    while(max->next != head && max->val <= max->next->val)
        max = max->next;
    
    ListNode *min = max->next, *curr = min;

    if(x >= max->val || x <= min->val)
    {
        ListNode *node = new ListNode(x);
        max->next = node;
        node->next = min;
    }
    else
    {
        while(curr->next->val < x)
            curr = curr->next;
            
        ListNode *node = new ListNode(x);
        node->next = curr->next;
        curr->next = node;
    }
    return head;
}

