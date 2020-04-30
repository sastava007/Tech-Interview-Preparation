/* One way is to traverse the binary tree and return 1, if it's a leaf node. If it's left subtree is null then check for right subtree, otherwise if right subtree is null then check for left
    If both of them are not null, then take minimum of both.
*/

int minDepth(Node *root)
{
    if(root==NULL)  //corner case, will not hit untill called on empty tree.
        return 0;
    
    if(root->left==NULL && root->right==NULL)   //base case, when we reach the leaf node.
        return 1;

    if(!root->left)
        return minDepth(root->right)+1;

    if(!root->right)
        return minDepth(root->left)+1;
    
    return min(minDepth(root->right), minDepth(root->left))+1;
}

/*  But above menthod may end up with complete traversal of binary tree even when leaf node is close to root, so as always a better solution exists using Level Order Traversal */

int minDepth(Node *root)
{
    queue<pair<Node*, int>> q;
    
    if(root==NULL)
        return 0;
    
    q.push({root, 1});

    while (!q.empty())
    {
        pair<Node *, int> temp = q.front();
            q.pop(); 

        if(temp.first->left==NULL && temp.first->right==NULL)
            return temp.second;

        if(temp.first->left!=NULL)
            q.push({temp.first->left, temp.second+1});
            
        if(temp.first->right!=NULL)
            q.push({temp.first->right, temp.second+1});
    }
}