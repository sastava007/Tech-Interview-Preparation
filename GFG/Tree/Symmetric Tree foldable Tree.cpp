/* Give a binaty tree, we have to find whether a tree is symmetric or not */
/* 
    1. For given two trees, if both trees are empty then they are mirror images of one another.
    Else they have to satisfy following conditions:
    2. Root values of both trees have to be same.
    3. Left sub-tree of tree1 should be mirror image of right sub-tree of tree2.
    4. Right sub-tree of tree1 should be mirror image of left sub-tree of tree2.
*/


bool isSymmetricUtil(Node* root1, Node* root2)
{
    if(root1==NULL && root2==NULL)
        return true;
    if(root1==NULL || root2==NULL)
        return false;
        
    if(root1->data==root2->data)    
    {
        if(isSymmetricUtil(root1->left, root2->right))
            return isSymmetricUtil(root1->right, root2->left);
    }
    
    return false;
}

bool isSymmetric(struct Node* root)
{
    return isSymmetricUtil(root, root);
}


/* This approach can be modified further to check if a tree is foldable or not, where we just need to check if left and right subtree of tree are structure wise same */
bool IsFoldable(Node* root1, Node* root2)
{
    if(root1==NULL && root2==NULL)
        return true;
    
    if(root1==NULL || root2==NULL)
        return false;
        
    if(IsFoldable(root1->left, root2->right))
    {
        return IsFoldable(root1->right, root2->left);
    }
    
    return false;
}

bool IsFoldable(Node* root)
{
    return IsFoldable(root, root);
}