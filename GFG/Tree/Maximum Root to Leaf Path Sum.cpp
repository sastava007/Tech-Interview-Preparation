/* This will return the maximum path sum from root node to leaf node */

int rootToLeafSum(Node* root)
{
    if(root==NULL)
        return 0;
    if(root->left==NULL && root->right==NULL)   //this line is though can be avoided becz then our return statement will hande when root->left=null and root->right=null then it would automatically gives the value present at root node
        return root->data;

    return (max(rootToLeafSum(root->left), rootToLeafSum(root->right)) + root->data);

}

/* This will print the path with given maximum sum from root node to leaf node, similar to https://practice.geeksforgeeks.org/problems/root-to-leaf-path-sum/1 */
bool printPath(Node* root, int sum)
{
    if(root==NULL)
        return (sum==0);

    /* if(root->left==NULL && root->right==NULL)
        return (root->data==sum); */

    bool left=printPath(root->left, sum-root->data);
    bool right=printPath(root->right, sum-root->data);
    
    if(left||right)
        cout<<root->data<<"-> ";

    return (left||right);
}