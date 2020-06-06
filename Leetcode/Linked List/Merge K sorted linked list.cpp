/* Using D&C we can solve divide this problem by pairing & mergeing 2 sorted linked list which can be done in O(n) time.
    After the first interval, we'll end up having K/2 lists, after second interval we'll end up having K/4 lists and so on, it continues untill we have just one list.
    So, here we can see our range of K keep on decreasing by factor of 2 so overall TC is O(NlogK), where N is total no. of nodes
    
    Space Complexity: O(1) as we're doing it iteratively so it will not consusme any stack space unlike O(logK)
    Reference: https://afteracademy.com/blog/merge-k-sorted-lists

 */

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        int k = lists.size();
        if(k==0)
            return NULL;
        
        int interval = 1;
        while(interval<k)
        {
            int i=0;
            while(interval+i<k)
            {
                lists[i]=mergeTwoSortedLists(lists[i], lists[interval+i]);
                i=i+interval*2;
            }
            interval *= 2;
        }
        
        return lists[0];
    }
    
private:
    ListNode* mergeTwoSortedLists(ListNode* a, ListNode* b)
    {
       if(a==NULL)
           return b;
        if(b==NULL)
            return a;
        
        ListNode* output  = NULL;
        
        if(a->val < b->val)
        {
            output = a;
            a=a->next;
        }
        else
        {
            output=b;
            b=b->next;
        }
        
        ListNode* curr = output;
        while(a!=NULL && b!=NULL)
        {
            if(a->val<b->val)
            {
                curr->next=a;
                a=a->next;
            }
            else
            {
                curr->next=b;
                b=b->next;
            }
            curr=curr->next;
        }
            
        if(a!=NULL)
            curr->next=a;
        if(b!=NULL)
            curr->next=b;
        
        return output;
    }
};