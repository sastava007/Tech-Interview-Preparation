/* 
    Given a BST with unique nodes, modify it such that every node has a new value equal to the sum of the values of the original tree that are greater than or equal to node's value.
    Idea: is to start traversing from the largest value to the smallest value in BST, and while doing so keep on updating the node's value as well as sum of value obtained so far.
*/

class Solution {
    
public:
    TreeNode* bstToGst(TreeNode* root)
    {
       if(!root)
           return root;
        
        int sum = 0;
        util(root, sum);
        return root;
    }
private:
    void util(TreeNode* root, int &sum)
    {
        if(!root)
            return;
        
        util(root->right, sum);
        root->val += sum;
        sum = root->val;
        
        util(root->left, sum);
    }
};