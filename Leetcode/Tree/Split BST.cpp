/* 
    Given a BST with root node, and a target value V, split the tree into two subtrees where one subtree has nodes that are all smaller or equal to the target value, while the other subtree has all nodes that are greater than the target value.
    We've to try to maintain the structure of the original tree, i.e a child C with parent P if both lies in same subtree then here also P should be parent of child C.

    Idea: Is to use a DFS, with condition that if target is greater than root->val then consider the right subtree else consider the left subtree.
    The first tree in returned array is one which is smaller than target, and other one is larger.
    If root is null then return [null, null]
    If target < root->val then call for left subtree and attach the root->left with second element of returned array becz it will be larger than target but still lesser than root node value
    And similarly, if target >= root->val, then call for right subtree and attach the root->left with first element of returned array as it is lesser than target but sill greater than root node value. 

*/

vector<node*> splitBST(node* root, int target)
{
    vector<node*> temp = {NULL, NULL};

    if(root==NULL)
    {
        return temp;
    }

    if(target < root->val)
    {
        temp = splitBST(root->left, target);
        root->left = temp[1];
        temp[1] = root;
    }
    else
    {
        temp = splitBST(root->right, target);
        root->right = temp[0];
        temp[0] = root;
    }

    return temp;
}

/* Iterative method using stack<> to simulate the above recursion */
public TreeNode[] iterative(TreeNode root, int v) {

    if (root == null) {
        return new TreeNode[2];
    }

    TreeNode[] out = new TreeNode[2];
    Stack<TreeNode> s = new Stack<>();
    TreeNode tmp = root;

    while (tmp != null) {       // push all considered nodes into stack
        s.push(tmp);
        tmp = (v < tmp.val) ? tmp.left : tmp.right;
    }

    while (!s.isEmpty()) {
        tmp = s.pop();
        if (v < tmp.val) {
            tmp.left = out[1];
            out[1] = tmp;
        } else {
            tmp.right = out[0];
            out[0] = tmp;
        }
    }

    return out;
}
