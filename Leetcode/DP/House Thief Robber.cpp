/* 
    To get the max amount of money, either we rob root or not.
    If we rob root, then we can rob the (root.left.left, root.left.right, root.right.left, root.right.right) wheras if we don't rob the root then we can rob the rob.left and rob.right
    
    So the final answer will be maximum of both the conditions, and instead of calling rob() each time which leads to repeated subproblem and calcuating the result we can basically cache the result and use whenver we need. This lead to a DP solution

    TC & Space: O(N)
*/

public int rob(TreeNode root) {
    return robSub(root, new HashMap<>());
}

private int robSub(TreeNode root, Map<TreeNode, Integer> map) {
    if (root == null) return 0;
    if (map.containsKey(root)) return map.get(root);
    
    int val = 0;
    
    if (root.left != null) {
        val += robSub(root.left.left, map) + robSub(root.left.right, map);
    }
    
    if (root.right != null) {
        val += robSub(root.right.left, map) + robSub(root.right.right, map);
    }
    
    val = Math.max(val + root.val, robSub(root.left, map) + robSub(root.right, map));   // max(rob_root_node, not_rob_root_node)
    map.put(root, val);
    
    return val;
}

/* Clever Solution: Without Using hashing */

int rob(TreeNode* root)
{
    auto it = util(root);
    return max(it.first, it.second);
}
pair<int,int> util(TreeNode* root)      // first value represents maximum amount possible if we don't rob the root, second value represents maximum amount possible if we rob the root
{
    pair<int,int> res({0,0});
    if(root==NULL)
        return res;

    pair<int,int> left = util(root->left);
    pair<int,int> right = util(root->right);

    res.first = max(left.first, left.second) + max(right.first, right.second);  // if not robbing root
    res.second = root->val + left.first + right.first;      // if rob the root

    return res;
}