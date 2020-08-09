/* Check whether it's possible to get given sum from root to leaf node */

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) 
    {    
        if(root==NULL)
        return false;
    
        if(root->left==NULL && root->right==NULL)
            return (root->val==sum);

        bool leftPathSum = hasPathSum(root->left, sum-root->val);
        bool rightPathSum = hasPathSum(root->right, sum-root->val);

        return (leftPathSum || rightPathSum);
    }
};

/*  Find all root-to-leaf paths where each path's sum equals the given sum */

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) 
    {
        vector<vector<int>> result;
        if(root==NULL)
            return result;   
        util(root, result, vector<int>({}), sum);
        return result;
    }

    void util(TreeNode* root, vector<vector<int>> &result, vector<int> path, int sum)   // We can also make this path to pass by ref. but in that we've to pop the last entered element
    {                                                                                   // passing by value takes more time to copy the elements that's why should be avoided
        if(root==NULL)
            return;
        
        if(!root->left && !root->right)
        {
            if(sum==root->val)
            {
                path.push_back(root->val);
                result.push_back(path);
            }
            return;
        }

        path.push_back(root->val);
        util(root->left, result, path, sum-root->val);
        util(root->right, result, path, sum-root->val);
    }
};

/*  
    Find the number of paths that sum to a given value.
    This problem can be visualized to classical problem of finding no. of subarrays with sum K which we solve by using a hash-map.
    Using the same idea here we can maintain a hash-table with prefix-sum and it's frequency and check if (prefix_sum - target) already exist or not.

*/

int pathSum(TreeNode* root, int target) 
{
    if(root == NULL)
        return 0;
    
    unordered_map<int, int> hash;
    hash[0] = 1;
    
    int ans = 0;
    
    util(root, hash, 0, target, ans);
    return ans;
}
void util(TreeNode* root, unordered_map<int, int> &hash, int prefixSum, int target, int &ans)
{
    if(root==NULL)
        return;
    
    prefixSum += root->val;
    if(hash.find(prefixSum-target)!=hash.end())
        ans += hash[prefixSum-target];
    
    hash[prefixSum]++;
    
    util(root->left, hash, prefixSum, target, ans);
    util(root->right, hash, prefixSum, target, ans);
    
    hash[prefixSum]--;
}