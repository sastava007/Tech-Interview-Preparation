int ans;
int diameterUtil(Node* node) 
{
    if(node==NULL)
        return 0;
    
    int longestPathInLeftSubtree = diameterUtil(node->left);
    int longestPathInRightSubtree = diameterUtil(node->right);
    
    ans=max(ans, longestPathInLeftSubtree + longestPathInRightSubtree + 1);
    
    return max(longestPathInLeftSubtree,longestPathInRightSubtree)+1;   //this will give longest in subtree rooted under current node.

int diameter(Node* node)
{
   ans=0;
   int temp = diameterUtil(node);
   return ans;
}