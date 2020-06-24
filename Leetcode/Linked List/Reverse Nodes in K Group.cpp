/*  Reverse the nodes in group of K, and if number of nodes to reverse is less than K then leave it as it is.

    Idea is to reverse the entire group by swapping or reversing the direction of individual arrows b/w adjacent nodes.
    We'll use 3 pointers, [prev, curr, nex]  nex will always be one node ahead of curr, and we'll be reversing the direction of arraw b/w these 2 nodes

    TC: O(N) and Space: O(1)
*/

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        if(head==NULL || k==1)
            return head;
        
        int n=0;
        ListNode preHead(0);
        preHead.next = head;
        
        ListNode *curr = &preHead, *nex, *prev = &preHead;
            
        while(curr->next)      // find length or no. of nodes
        {
            n++;
            curr = curr->next;
        }
        
        while(n>=k)
        {
            curr = prev->next;
            nex = curr->next;
            
            for(int i=1; i<k; i++)
            {
                curr->next = nex->next;     // save the address of next node ahead of us
                nex->next = prev->next;     // make the current node points to prev
                prev->next = nex;           // make previous one points to current
                
                nex = curr->next;           // use the stored pointer to move to next node
            }
            prev = curr;
            n -= k;
        }
        return preHead.next;
    }
};