/*
    Given a LL, delete consecutive sequences of nodes that sum to 0 untill there's no such subsequence.

    Idea: Similar to finding `subarray sum = 0` Can be solved using a hash-map by maintaing a prefix sum and each time we find a prefix sum that already exists
    we know that there exist a subsequence which sums to 0.

    Note: Here the thing to be noted is that once we encounter such a subsequence with 0 sum, then we also need to clear map becz there could be prefix sum of nodes that has
    been deleted and also need to reset the curr to dummy or starting node. This
    TC: O(N) & Space: O(N)
*/

class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) 
    {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *curr = dummy;
        
        unordered_map<int, ListNode*> m;    // not inserting 0 explicitly, becz that case would be dealt with dummy node which has 0 value itself
        int prefix = 0;
        
        while(curr)
        {
            prefix += curr->val;
            if(m.find(prefix) != m.end())
            {
                m[prefix]->next = curr->next;
                prefix = 0;
                m.clear();
                curr = dummy;
            }
            else
            {
                m[prefix] = curr;
                curr = curr->next;   
            }
        }
        return dummy->next;
    }
};