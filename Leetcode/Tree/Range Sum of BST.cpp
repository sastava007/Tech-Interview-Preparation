/*  Find sum of all the nodes that lies in range [L,R] 
    Optimize little a bit: Only go for left subtree when lower limit is less than current root node value becz there may be case that if current node value is 10 and your range is [12,25] then 
    there's no point in going for left subtree. Similarly the right limit should be greater than root node value.

    TC: O(N) and Space: O(h) due to recursion stack
*/

class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) 
    {
        int sum=0;
        util(root, L, R, sum);
        
        return sum;
    }
private:
    void util(TreeNode* root, int l, int r, int &sum)
    {
        if(root==NULL)
        {
            sum += 0;
            return;
        }
        
        if(root->val>=l && root->val<=r)
            sum += root->val;
        
        if(l<root->val)   
            util(root->left, l, r, sum);
        if(r>root->val)
            util(root->right, l, r, sum);
    }   
};

/* Iterative implementation */
class Solution 
{
    public int rangeSumBST(TreeNode root, int L, int R) {
        int ans = 0;
        Stack<TreeNode> stack = new Stack();
        stack.push(root);
        while (!stack.isEmpty()) {
            TreeNode node = stack.pop();
            if (node != null) {
                if (L <= node.val && node.val <= R)
                    ans += node.val;
                if (L < node.val)
                    stack.push(node.left);
                if (node.val < R)
                    stack.push(node.right);
            }
        }
        return ans;
    }
}