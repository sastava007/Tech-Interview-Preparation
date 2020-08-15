/* 
    Given root nodes of 2 tree, check if T has exactly the same structure and node values with a subtree of S. A subtree of S is a tree consists of a node in S and all of this node's descendants. The tree S could also be considered as a subtree of itself.

    TC: O(M*N) where M and N are number of nodes in both the trees.
*/

class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) 
    {
        if(!s && !t)
            return true;
        if(!s || !t)
            return false;
        
        if(s->val == t->val)
        {
            bool flag = check(s,t);
            if(flag==true)
                return true;
        }
        
        bool left = isSubtree(s->left, t); 
        bool right = isSubtree(s->right, t);

        return (left || right);
    }
private:
    bool check(TreeNode* s, TreeNode* t)
    {
        if(!s && !t)
            return true;
        if(!s || !t)
            return false;

        if(s->val == t->val)
        {
            bool left = check(s->left, t->left);
            bool right = check(s->right, t->right);

            return (left && right);
        }
        return false;
    }
};
