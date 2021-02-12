/* 
    Given a LL, delete N nodes after a gap of M nodes. And while doing so if ever we get short of nodes than adjust accordingly.
    
    Example: [1,2,3,4,5,6,7,8,9,10,11,12,13], m = 2, n = 3   =>   [1,2,6,7,11,12]

    TC: O(N) & Space: O(1)
*/

void linkdelete(struct Node *head, int m, int n)
{
    while (head)    // main loop that traverse through the entire LL
    {
        for(int i=1; i<m && head; i++)  // skip M nodes
            head = head->next;
            
        if(head == NULL)
            return;
            
        Node *curr = head->next;
        for(int i=0; i<n && curr; i++)  // starting from curr, delete N nodes
        {
            Node *temp = curr;
            curr = curr->next;
            delete(temp);
        }
        head->next = curr;  // later join the list again
        head = head->next;
    }
}