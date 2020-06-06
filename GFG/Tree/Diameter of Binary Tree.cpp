/* First check definition for Diameter of binary Tree: i.e if they are asking for no. of nodes on maximum path or edge of maximum path*/

int ans;
int diameterUtil(Node* node) 
{
    if(node==NULL)
        return 0;
    
    int longestPathInLeftSubtree = diameterUtil(node->left);
    int longestPathInLeftSubtree = diameterUtil(node->right);
    
    ans=max(ans, longestPathInLeftSubtree + longestPathInRightSubtree + 1); //here we are returning no. of nodes on longest path b/w two leaves of binary tree
    
    return max(longestPathInLeftSubtree,longestPathInRightSubtree)+1;   //this will give longest in subtree rooted under current node.

int diameter(Node* node)
{
   ans=0;
   int temp = diameterUtil(node);
   return ans;
}

/* LC version: Here we've to return the edges and not nodes, so don't include the root node while checking for maximum */
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) 
    {
        int diameter = 0;
        int dump = util(root, diameter);
        
        return diameter;
    }
    
private: 
    int util(TreeNode* root, int &diameter)
    {
        if(root==NULL)
            return 0;
        
        int longestPathInLeftSubtree = util(root->left, diameter);
        int longestPathInLeftSubtree = util(root->right, diameter);
        
        diameter = max(diameter, longestPathInLeftSubtree + longestPathInLeftSubtree);
        
        
        return max(longestPathInLeftSubtree, longestPathInLeftSubtree) + 1;
        
    }
};

/* Using iterative postorder traversal */
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) 
    {
        if (!root) 
        {
            return 0;
        }
        
        int diameter = 0;
        unordered_map<TreeNode*, int> depths;
        stack<TreeNode*> todo;
        todo.push(root);
        while (!todo.empty())
        {
            TreeNode* node = todo.top();
            if (node -> left && depths.find(node -> left) == depths.end()) {
                todo.push(node -> left);
            } else if (node -> right && depths.find(node -> right) == depths.end()) {
                todo.push(node -> right);
            } else {
                todo.pop();
                int l = depths[node -> left], r = depths[node -> right];
                depths[node] = max(l, r) + 1;
                diameter = max(diameter, l + r);
            }
        }
        return diameter;
    }
};