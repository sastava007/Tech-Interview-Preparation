/* A tree is said to be balanced if the difference b/w height of left and right subtree of any node is not greater than 1 */

bool flag;
int isBalancedUtil(Node *root)
{
    if(root==NULL)
    {
        return 0;
    }
    
    int left=isBalancedUtil(root->left);
    int right=isBalancedUtil(root->right);
    
    if(abs(left-right)>1)
    flag=false;
    
    return max(left,right)+1;
}

bool isBalanced(Node *root)
{
    flag=true;
    int x = isBalancedUtil(root);
    return flag;
}
