/* Using recursive preorder traversal */

class Solution {
public:
    bool isValidBST(TreeNode* root) 
    {
        return util(root, NULL, NULL);    
    }
    
private:
    bool util(TreeNode* root, TreeNode *minNode, TreeNode *maxNode)
    {
        if(root==NULL)
            return true;
        
        if((minNode && root->val<=minNode->val) || (maxNode && root->val>=maxNode->val))
            return false;
        
        bool left = util(root->left, minNode, root);
        bool right = util(root->right, root, maxNode);
        
        return (left && right);
    }
};

/* Using iterative inorder traversal will give sorted array. So keep on checking if the current_val <= prev_val then return false*/
class Solution
{
    public:
    bool isValidBST(Node* root)
    {
        stack<Node*> s;
        Node* curr = root;
        long prev = LONG_MIN;

        while (!s.empty() || curr)
        {
            if(curr)
            {
                s.push(curr);
                curr=curr->left;    //going left
            }
            else
            {
                curr = s.top();   //going top
                s.pop();
                if(curr->data <= prev)
                    return false;
                prev = curr->data;

                curr=curr->right;    //going right
            }
        }
        return true;
    }
}