/*
    Intution can be formed for this problem from diameter of binary tree
    https://www.geeksforgeeks.org/find-maximum-path-sum-two-leaves-binary-tree/ 
*/

int maxPathSumUtil(Node* root, int& ans)
{
    if(!root)
        return 0;
    if(!root->left && !root->right)
        return root->data;
        
    int maxPathSumLeftSubtree = maxPathSumUtil(root->left, ans);
    int maxPathSumRightSubtree = maxPathSumUtil(root->right, ans);

    if(root->left && root->right)
    {
        ans = max(ans, maxPathSumLeftSubtree+maxPathSumRightSubtree+root->data);
        return max(maxPathSumLeftSubtree, maxPathSumRightSubtree)+root->data;
    }
        
    return !root->left?maxPathSumRightSubtree+root->data : maxPathSumLeftSubtree+root->data;
}

int maxPathSum(Node* root)
{ 
    int ans = INT_MIN;
    maxPathSumUtil(root, ans);
    return ans;
}