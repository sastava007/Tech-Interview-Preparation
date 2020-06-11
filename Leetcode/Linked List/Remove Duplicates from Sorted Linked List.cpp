/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// This removes all the duplicated nodes [1->1->2->5->7] = [1->2->5->7]

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) 
    {
        ListNode* curr = head;
        while(curr)
        {
            while(curr->next && curr->val == curr->next->val)
            {
                ListNode* temp = curr->next;
                curr->next = curr->next->next;

                delete(temp);       // free the memory
            }
            curr = curr->next;
        }
        return head;
    }
};

/* Remove all the duplicate nodes, such that it only has distinct nodes remaining */

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) 
    {
        ListNode* dummy = new ListNode(0);      //here we are using dummy node, becz it may be possible that we've to delete the first node itself
        dummy->next = head;
        
        ListNode* pre = dummy;  //pre- predecessor that make sure that all nodes before this has no duplicates
        while(pre->next)
        {
            ListNode* node = pre->next;
            while(node->next && node->val == node->next->val)   //skip the duplicate elements
            {
                node=node->next; 
            }
            
            if(node != pre->next)   // node aage wala hai, jo abhi non duplicate ko point kar raha hoga
            {
                ListNode* temp = pre->next;
                pre->next = node->next;
                delete(temp);
            }
            else
            {
                pre = node;
            }
        }
        
        return dummy->next;
    }
};