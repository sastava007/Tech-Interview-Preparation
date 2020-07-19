/* 
    Convert a given array to a maximum BT, where root node is the maximum value in array.
    - The left subtree is also a maximum tree constructed from left part of array divided by the maximum number.
    - The right subtree is also a maximum tree constructed from right part of array divided by the maximum number.
*/

/* Using simple recursion O(N^2) */
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) 
    {
        return util(nums, 0, nums.size());
    }
private:
    TreeNode* util(vector<int>& nums, int l, int r)
    {
        if(l==r)
            return NULL;
        int max_index = max_element(nums.begin()+l, nums.begin()+r) - nums.begin();
        TreeNode* root = new TreeNode(nums[max_index]);
        
        root->left = util(nums, l, max_index);
        root->right = util(nums, max_index+1, r);
        
        return root;
    }
};

/* Using monotonic stack, to store the nodes in descending order TC: O(N) */

TreeNode* constructMaximumBinaryTree(vector<int>& nums) 
{
    stack<TreeNode*> stk;
    for (int num : nums) {
        TreeNode* node = new TreeNode(num);
        while (!stk.empty() && stk.top() -> val < node -> val)  // For each number, we keep popping the stack until empty or a bigger number is found
        {
            node -> left = stk.top();
            stk.pop();
        }
        if (!stk.empty()) {
            stk.top() -> right = node;
        }
        stk.push(node);
    }
    while (stk.size() > 1) {
        stk.pop();
    }
    return stk.top();
}