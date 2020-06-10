/*  
    One way is to use BFS to do a level order traversal, and whenever we encounter a NULL node then mark it and make sure that we don't encounter any non NULL node after that neither in it's own 
    level nor in it's down level.

    O(N) time and O(N) space
 */

class Solution {
public:
    bool isCompleteTree(TreeNode* root) 
    {
        bool emptyBefore = false;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* curr = q.front();
            q.pop();
            
            if(emptyBefore && curr->left)
                return false;
            else if(curr->left)
                q.push(curr->left);
            
            emptyBefore = !curr->left?true:false;
            
            if(emptyBefore && curr->right)
                return false;
            else if(curr->right)
                q.push(curr->right);
            
            emptyBefore = !curr->right?true:false;
        }
        
        return true;
    }
};

/* Recursive method, by first calculating the total no. of nodes in a Binary Tree and then checking the position of each node */

int countNodes(Node* root) 
{ 
    if (root == NULL) 
        return (0); 
    return (1 + countNodes(root->left) + countNodes(root->right)); 
} 

bool isComplete ( Node* root, int index, int number_nodes) 
{ 
    if (root == NULL) 
        return (true); 
  
    // If index assigned to current node is more than number of nodes in tree, then tree is not complete 
    if (index >= number_nodes) 
        return (false); 

    return (isComplete(root->left, 2*index + 1, number_nodes) && isComplete(root->right, 2*index + 2, number_nodes)); 
} 