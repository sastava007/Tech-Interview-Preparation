/*  My idea is to peform a postorder DFS traversal and while doing so maintaing the maximum value of the path sum
    There can be 4 ways in which the current node can pe part of maximum path sum:
    1. root->val
    2. root->val + maxPathSumInLeftSubtree
    3. root->val + maxPathSumInRightSubtree
    4. root->val + maxPathSumInLeftSubtree + maxPathSumInLeftSubtree
    O(n) time and O(n) space
*/
class Solution {
public:
    int ans;

    int maxPathSum(TreeNode* root)
    {
        ans=INT_MIN;
        int temp = maxPathSumUtil(root);
        
        return ans;
    }

private:
    int maxPathSumUtil(TreeNode* root)
    {
        if(root==NULL)
            return 0;

        int left = maxPathSumUtil(root->left);
        int right = maxPathSumUtil(root->right);

        ans = max({ans, root->val, left+right+root->val, left+root->val, right+root->val});

        return max(root->val, max(left,right)+root->val);
    }
};

/* Editorial Solution */
class Solution {
    public:

    int maxPathSum(TreeNode* root)
    {
        int maxsum = INT_MIN;
        
        int dump = util(root, maxsum);
        
        return maxsum;
    }
    
    int util(TreeNode* root, int &maxsum)
    {
        if(root==NULL)
            return 0;
        
        int left = max(0, util(root->left, maxsum));
        int right = max(0, util(root->right, maxsum));
        
        maxsum = max(maxsum, left+right+root->val);
        
        return max(left, right)+root->val;
    }
};