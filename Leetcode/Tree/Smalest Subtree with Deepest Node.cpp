/* 
    So basically we need to find LCA of the most deepest node, if there are nodes having same depth then return their root, else return the node with greatest Depth(from bottom).
    Intuitively, we should be traversing from the children to the parent and calculate the height from bottom. So the null nodes would have height 0. The leaf nodes would have the
    height 1 and the root would have the max height.
 
    At each node, we keep a pair<height_of_node_from_bottom, node>. At a given node, if we realize that the leftHeight == rightHeight, it means we have found the deepest subtree
    rooted at node. If leftHeight > rightHeight, it means the deepest subtree must be rooted at left child. If rightHeight > leftHeight, it means the deepest subtree must be rooted
    at right child. As we need to traverse bottom-top so we'll use Postorder traversal.

    PS: This problem is similar to finding LCA of deepest leaves.
    PS: We can also do this in 2 phase, first to find the deepest node and then again to find their LCA. 
 */


class Solution {
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root)
    {
        auto it = dfs(root);
        return it.second;
    }
private:
    pair<int, TreeNode*> dfs(TreeNode* root)
    {
        if(root==NULL)
            return {0, NULL};
        
        auto left = dfs(root->left);
        auto right = dfs(root->right);
        
        if(left.first == right.first)   // if depth of both the subtree are same, then return root
            return {left.first+1, root};
        else if(left.first<right.first)     // if depth of left subtree is greater than return left else right
            return {right.first+1, right.second};
        else
            return {left.first+1, left.second};
    }
};