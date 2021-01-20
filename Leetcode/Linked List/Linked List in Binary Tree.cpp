/* 
    Given a binary tree and a linked list, find whether there exist a downward path in binary tree that has all the elements of LL.
    Idea: is to check for each node if there exists any path starting from that node having all nodes of LL if yes then return true else check in its left & right subtree.

    TC: O(N * min(H, L)) here N = no. of nodes in binary tree, H = height of binary tree and L = length of linked list.
    Space: O(H)
*/

class Solution {
public:
    
    bool isSubPath(ListNode* head, TreeNode* root) 
    {
        if (!head)
            return true;
        if (!root) 
            return false;
        return dfs(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }
    bool dfs(ListNode* head, TreeNode* root)  // check if there's a subPath starting from current node
    {
        if (!head) 
            return true;
        if (!root) 
            return false;
        
        return head->val == root->val && (dfs(head->next, root->left) || dfs(head->next, root->right));
    }
};