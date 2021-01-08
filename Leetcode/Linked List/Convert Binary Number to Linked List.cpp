/* 
    Smart Solution: With just one traversal using basic observation that as we move towards right, we multiply 2 to previous result and add current node value
*/

int getDecimalValue(ListNode* head) 
{
    int ans = head->val;
    head = head->next;
    
    while(head)
    {
        ans = ans*2 + head->val;    // OR ans = 1<<i | head->val  here | symbol means addition in bit manipulation
        head = head->next;
    }
    return ans;
}


/* Naive solution in 2 iterations, first finding size of linked list then converting binary to decimal */

int getDecimalValue(ListNode* head) 
{
    ListNode *temp = head;
    int count = 0, ans = 0;
    
    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    
    while(count--)
    {
        ans += (head->val * pow(2, count));
        head = head->next;
    }
    
    return ans;
}