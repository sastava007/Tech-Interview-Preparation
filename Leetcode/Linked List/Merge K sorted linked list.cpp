/*  
    Using D&C we can solve divide this problem by pairing & mergeing 2 sorted linked list which can be done in O(n) time.
    After the first interval, we'll end up having K/2 lists, after second interval we'll end up having K/4 lists and so on, it continues untill we have just one list.
    So, here we can see our range of K keep on decreasing by factor of 2 so overall TC is O(NlogK), where N is total no. of nodes
    
    Space Complexity: O(1) as we're doing it iteratively so it will not consusme any stack space unlike O(logK)
    Reference: https://afteracademy.com/blog/merge-k-sorted-lists
    
    TC: O(NlogK) and Space: O(1)
*/


class Solution {
private:
    ListNode* merge2Lists(ListNode *a, ListNode *b)
    {
        if(!a)
            return b;
        if(!b)
            return a;
        ListNode *dummy = new ListNode(0);
        ListNode *p = dummy;
        
        while(a && b)
        {
            if(a->val<b->val)
                p->next = a, a = a->next;
            else
                p->next = b, b = b->next;
            p = p->next;
        }
        p->next = a?a:b;
        return dummy->next;
    }
        
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        int k = lists.size();
        if(k==0)
            return NULL;
        
        for(int interval = 1; interval<k; interval *=2)
        {
            int i = 0;
            while(interval+i < k)
            {
                lists[i] = merge2Lists(lists[i], lists[interval+i]);
                i = i + 2*interval;
            }
        }
        return lists[0];
    }
};