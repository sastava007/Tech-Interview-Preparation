/* https://practice.geeksforgeeks.org/problems/root-to-leaf-path-sum/1 */

bool hasPathSum(Node *node, int sum) 
{
    if(node==NULL)
        return (sum==0);
    
    if(node->left==NULL && node->right==NULL)
        return (node->data==sum);
        
    bool leftPathSum = hasPathSum(node->left, sum-node->data);
    bool rightPathSum = hasPathSum(node->right, sum-node->data);
    
    return (leftPathSum || rightPathSum);
}