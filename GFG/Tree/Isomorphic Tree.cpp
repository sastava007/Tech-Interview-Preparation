/* 
    A tree is said to be isomorphic if, left and right subtree are either identical or mirror.
 */

bool isIsomorphic(Node *root1,Node *root2)
{
    if(root1==NULL && root2==NULL)
        return true;
    if(root1==NULL || root2==NULL)
        return false;
        
        
    bool isIdentical = isIsomorphic(root1->left, root2->left) && isIsomorphic(root1->right, root2->right);
    bool isMirror = isIsomorphic(root1->left, root2->right) && isIsomorphic(root1->right, root2->left);
    
    if(root1->data == root2->data)
    {
        return (isIdentical || isMirror);
    }
    
    return false;
}