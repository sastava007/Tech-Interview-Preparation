/* 
    Here we don't have have head* instead we've to delete the given node itself and as we know that before deleting a node we've to modify the next pointer which isn't possible
    in this case coz we don't have access to previous node. So simple hack is to swap the values of node and node->next pointer and delete the next node.

    TC & Space: O(1)
*/

class Solution {
public:
    void deleteNode(ListNode* node) 
    {
     
        int temp = node->val;
        node->val = node->next->val;
        node->next->val = temp;
        
        ListNode *toBeDeleted = node->next;
        node->next = node->next->next;
        
        
        delete(toBeDeleted);
    }
};