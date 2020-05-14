/*
    Intution can be formed for this problem from diameter of binary tree
    https://www.geeksforgeeks.org/find-maximum-path-sum-two-leaves-binary-tree/ 
*/

int ans;

int maxPathSumUtil(Node* root)
{
    if(root==NULL)
        return 0;

    int maxSumRootLeafLeft = maxPathSumUtil(root->left);
    int maxSumRootLeafRight = maxPathSumUtil(root->right);

    if(root->left && root->right)
    {
        ans=max(ans, maxSumRootLeafLeft+maxSumRootLeafRight+root->data);
        return max(maxSumRootLeafLeft, maxSumRootLeafRight)+root-data;
    }

    !root->left?return(maxSumRootLeafRight+root->data) :  return(maxSumRootLeafLeft+root->data);
}

int maxPathSum(Node *root) 
{
    ans = INT_MIN;
    int temp = maxPathSumUtil(root);
    
    return ans;
}

    if(!root->left && !root->right)
        return root->data;