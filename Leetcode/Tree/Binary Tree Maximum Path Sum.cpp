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

/* My Solution */
class Solution {
public:
    int ans;

    int maxPathSumUtil(TreeNode* root)
    {
        if(root==NULL)
            return 0;

        int left = maxPathSumUtil(root->left);
        int right = maxPathSumUtil(root->right);

        ans = max({ans, root->val, left+right+root->val, left+root->val, right+root->val});

        return max(max(left,right)+root->val, root->val);
    }
    
    int maxPathSum(TreeNode* root)
    {
        ans=INT_MIN;
        int temp = maxPathSumUtil(root);
        
        return ans;
    }
    
};