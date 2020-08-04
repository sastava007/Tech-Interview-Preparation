/*  Convert the Binary Tree to a flatten linked list in-place without using any extra space

    So what actually we're interested in doing is converting the tree into a linear shape(right skewed), so all we have to do it to check if there exist some left subtree then we have to process it and convert it into a linear shape and append this left subtree before the right node, and make left one NULL. So one word is to convert the left subtree to right subtree and make left one NULL.

    TC: O(N) & O(1) space Morris Traversal

             1
            / \
           2   5
          / \   \
         3   4   6

           1
            \
             2
              \
               3
                \
                 4
                  \
                   5
                    \
                     6

*/

class Solution {
public:
    void flatten(TreeNode* root) 
    {
        if(root==NULL)
            return;
        if(!root->left && !root->right)
            return;
        
        TreeNode* node = root;
        while(node)
        {
            if(node->left)
            {
                TreeNode* pre = node->left;
                while(pre->right)
                {
                    pre=pre->right;
                }
                pre->right = node->right;
                node->right = node->left;
                node->left = NULL;                   
            }
            node = node->right;
        }
    }
};

/* Concise Solution:  Recursive O(N) and O(h) */
private TreeNode prev = null;

public void flatten(TreeNode root) 
{
    if (root == null) 
    {
        return;
    }

    flatten(root.right);
    flatten(root.left);
    root.right = prev;
    root.left = null;
    prev = root;
}