/*  Find the least absolute difference between any node value of the BST and the given integer. 
    Naive: Simple preorder traversal
    Optimised: Use properties of BST

    TC: O(logn) or O(H) where H is height of binary tree
 */

void util(Node* root, int k, int &minDiff, int &minDiffKey)
{
    if(root==NULL)
    return;
    
    if(root->data==k)
    {
        minDiffKey=root->data;
        minDiff=0;
        return;
    }
    
    //update our minDiff obtained so far
    if(abs(root->data-k)<minDiff)
    {
        minDiff=abs(root->data-k);
        minDiffKey=root->data;
    }
    
    if(k<root->data)
        util(root->left, k, minDiff, minDiffKey);
    else
        util(root->right, k, minDiff, minDiffKey);
    
}

int minDiff(Node *root, int k)
{
    int minDiff=INT_MAX;
    int minDiffKey=-1;
    
    util(root, k, minDiff, minDiffKey);
    
    return minDiff;
}