/*  
    Intution: To make sure min/max values belong to an ancestor, we track min/max from the root till the leaf, and pick the biggest difference among all leaves.

    and check if the difference between the (max_value - min_value) is greater than the current difference in such a case update the diff 
*/

class Solution {
public:
    int maxAncestorDiff(TreeNode* root) 
    {
        int diff=INT_MIN;
        
        util(root, root->val, root->val, diff);
        
        return diff;
    }
private:
    void util(TreeNode* root, int cur_min, int cur_max, int &diff)
    {
        if(root==NULL)
           return;

        diff = max(diff, cur_max-cur_min);  // preorder traversal

        cur_min = min(cur_min, root->val);      
        cur_max = max(cur_max, root->val);
        
        util(root->left, cur_min, cur_max, diff);
        util(root->right, cur_min, cur_max, diff);
    }
};

/* Another approach */
class Solution {
public:
    int maxAncestorDiff(TreeNode* root) 
    {
        int ans = 0;
        
        if(!root)
            return ans;
        util(root, root->val, root->val, ans);
        return ans;
    }
private:
    void util(TreeNode* root, int minInSubtree, int maxInSubtree, int &ans)
    {
        if(!root)
            return;
              
        ans = max({ans, abs(minInSubtree-root->val), abs(maxInSubtree-root->val)});     // here I'm finding the max diff with each node value
        
        minInSubtree = min(minInSubtree, root->val);
        maxInSubtree = max(maxInSubtree, root->val);

        util(root->left, minInSubtree, maxInSubtree, ans);
        util(root->right, minInSubtree, maxInSubtree, ans);
    }
};