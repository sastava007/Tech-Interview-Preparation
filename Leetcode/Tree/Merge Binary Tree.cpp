/*  Given 2 binary trees, merge them. 
    Merge them in a way such that if both nodes exists then add values, otherwise keep the other node

    TC & Space: O(M) where M is the minimum number of nodes in both the trees

    Note: Ask the interviewer, whether we've to create a new tree or update the earlier one. 
*/

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2)
    {
        
        if(t1==NULL)
            return t2;
        if(t2==NULL)
            return t1;
        
        t1->val += t2->val;
        t1->left = mergeTrees(t1->left, t2->left);
        t1->right = mergeTrees(t1->right, t2->right);
        
        return t1;
    }
};