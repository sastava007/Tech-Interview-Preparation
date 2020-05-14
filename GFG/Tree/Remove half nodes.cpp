/* Remove all nodes which have just one child and return the root pointer of following new tree
    https://practice.geeksforgeeks.org/problems/remove-half-nodes/1
 */

Node *RemoveHalfNodes(Node *root)
{
   if(root==NULL)
    return NULL;
    
    if(!root->left && !root->right)
        return root;
    
    root->left = RemoveHalfNodes(root->left);
    root->right = RemoveHalfNodes(root->right);
    
    if(root->left && !root->right)
        return root->left;
    if(!root->left && root->right)
        return root->right;
        
    return root;
}