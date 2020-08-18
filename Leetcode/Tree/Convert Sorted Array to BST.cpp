/* 
    Convert a sorted array to a height balanced BST, such that diff of heiht of left & right subtree should always be less than 1.
    TC: O(N) & Space: O(logN)
*/

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {    
        return util(nums, 0, nums.size()-1);
    }
    TreeNode* util(vector<int> &nums, int left, int right)
    {   
        if(left > right)
            return NULL;
        
        int mid = left +(right-left)/2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = util(nums, left, mid-1);
        root->right = util(nums, mid+1, right);
        
        return root;
    }
};