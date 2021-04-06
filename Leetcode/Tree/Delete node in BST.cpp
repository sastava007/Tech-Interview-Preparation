/* 
    First find the node to be deleted, 3 cases are possible for that node either it has 0,1 children or both the later one is tricky to handle. 
    So find the smallest element in right subtree and points it's left to root->left.

    TC & Space: O(H) which in the worst case can be close to N if we a kinda skewed tree.

                        5
             4                    11
                                10
                               9
                             8
                           7
                         6
    And we've to delete (5) here O(N-2 or N-1)
*/

TreeNode* deleteNode(TreeNode* root, int key) 
{
    if(!root)
        return NULL;
    
    if(root->val < key)
        root->right = deleteNode(root->right, key);
    else if(root->val > key)
        root->left = deleteNode(root->left, key);
    else
    {
        if(root->left && root->right)
        {
            TreeNode *rightSmallest = root->right;
            
            while(rightSmallest->left)
                rightSmallest = rightSmallest->left;
            rightSmallest->left = root->left;
            
            return root->right;
        }
        return root->left?root->left:root->right;
    }
    return root;
}

/* 
    Instead of finding smallest/largest node in right/ left subtree we can also insert the one subtree into other.
    Using the simple approach as we used in insert into BST.
*/
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) 
    {
        if(!root)
            return NULL;
        
        if(root->val < key)
            root->right = deleteNode(root->right, key);
        else if(root->val > key)
            root->left = deleteNode(root->left, key);
        else
        {
            if(root->left && root->right)
            {
                return insertIntoBST(root->left, root->right);    
            }
            return root->left?root->left:root->right;
        }
        return root;
    }
private:
    TreeNode* insertIntoBST(TreeNode* root, TreeNode* node)
    {
        if(!root)
            return node;
        
        if(node->val < root->val)
            root->left = insertIntoBST(root->left, node);
        else
            root->right = insertIntoBST(root->right, node);
        return root;
    }
};

/* TC: O(H) & Space: O(1) using iterative method */
class Solution {
      private TreeNode deleteRootNode(TreeNode root) {
        if (root == null) {
            return null;
        }
        if (root.left == null) {
            return root.right;
        }
        if (root.right == null) {
            return root.left;
        }
        
        TreeNode next = findMin(root.right);
        next.left = root.left;
        return root.right;
    }
    
    private TreeNode findMin(TreeNode root) {
        while (root.left != null) {
            root = root.left;
        }
        return root;
    }
    
    public TreeNode deleteNode(TreeNode root, int key) {
        TreeNode cur = root;
        TreeNode pre = null;
        while(cur != null && cur.val != key) {
            pre = cur;
            if (key < cur.val) {
                cur = cur.left;
            } else if (key > cur.val) {
                cur = cur.right;
            }
        }
        if (pre == null) {
            return deleteRootNode(cur);
        }
        if (pre.left == cur) {
            pre.left = deleteRootNode(cur);
        } else {
            pre.right = deleteRootNode(cur);
        }
        return root;
    }
}