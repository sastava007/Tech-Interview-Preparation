/*  
    Intution: To make sure min/max values belong to an ancestor, we track min/max from the root till the leaf, and pick the biggest difference among all leaves.

    and check if the difference between the (max_value - min_value) is greater than the current difference in such a case update the diff 
*/

class Solution {
public:
    int maxAncestorDiff(TreeNode* root) 
    {
        int diff=INT_MIN;
        
        util(root, INT_MAX, INT_MIN, diff);
        
        return diff;
    }
    
private:
    void util(TreeNode* root, int mn, int mx, int &diff)
    {
        if(root==NULL)
           return;
        
        mn=min(mn, root->val);      //preorder traversal
        mx=max(mx, root->val);
        
        diff=max(diff, mx-mn);
        
        util(root->left, mn, mx, diff);
        util(root->right, mn, mx, diff);
    }
};