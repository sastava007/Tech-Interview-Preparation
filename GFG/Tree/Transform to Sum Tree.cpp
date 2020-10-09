/* 
    Given a binary tree, we've to tarnsform it to the Sum Tree.
    A sum tree is one which has its value equal to sum of left & right subtree.

    Leaf node has 0 sum
*/

int toSumTreeUtil(Node *node)
{
    if(node==NULL)
        return 0;
        
    int left = toSumTreeUtil(node->left);
    int right = toSumTreeUtil(node->right);
    
    int subtreeSum = left + right + node->data;
    
    node->data = left + right;
    return subtreeSum;
}

void toSumTree(Node *node)
{
    if(node==NULL)
        return ;
    
    int dump = toSumTreeUtil(node);
}