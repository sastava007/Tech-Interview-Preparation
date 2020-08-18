/*  My idea is to peform a postorder DFS traversal and while doing so maintaing the maximum value of the path sum seen so far
    There can be 4 ways in which the current node can pe part of maximum path sum:
    1. root->val
    2. root->val + maxPathSumInLeftSubtree
    3. root->val + maxPathSumInRightSubtree
    4. root->val + maxPathSumInLeftSubtree + maxPathSumInLeftSubtree
    O(n) time and O(H) space for recursive stack

    Note: There should be atleast 1 node, in path sum
    Edge Case: Try to have all negative nodes, then the one with least -ve value will be our answer
*/

class Solution {
public:
    int ans;

    int maxPathSum(TreeNode* root)
    {
        ans=INT_MIN;
        int temp = maxPathSumUtil(root);
        return ans;
    }

private:
    int maxPathSumUtil(TreeNode* root)
    {
        if(root==NULL)
            return 0;

        int left = maxPathSumUtil(root->left);
        int right = maxPathSumUtil(root->right);

        ans = max({ans, root->val, left+right+root->val, left+root->val, right+root->val});

        return max(root->val, max(left,right)+root->val);   // in either case we can't skip the root value, we have to include it. I mean, like we can't skip a particular node in path, if we're
                                                            // considering a path, then we've to consider all the nodes in that path. And also we can't return (left+root+right)
    }
};

/* To Print Path as Well TC & Space: O(N) */

int maxPathSum(TreeNode* root)
{
    int maxsum = INT_MIN, leftSum = INT_MAX, rightSum = INT_MAX;
    TreeNode* node = NULL;

    int dump = util(root, maxsum, leftSum, rightSum, node);
    vector<int> path, completePath;
    
    int flag = 0;
    
    getPath(node->left, leftSum, 0, path, completePath, flag);  // add the nodes from the left path
    completePath.push_back(node->val);  // add root node
    
    flag =1;
    getPath(node->right, rightSum, 0, path, completePath, flag);   // add the nodes from the right path
    
    for(int n: completePath)
        cout<<n<<"  ";
    
    return maxsum;
}
int util(TreeNode* root, int &maxsum, int &leftSum, int &rightSum, TreeNode* &node) // pass the pointer by reference
{
    if(root==NULL)
        return 0;

    int left = max(0, util(root->left, maxsum, leftSum, rightSum, node));  // As path can start & end at the same node, so we don't need to add the contribution from the left/right subtree
    int right = max(0, util(root->right, maxsum, leftSum, rightSum, node));

    if(left+right+root->val > maxsum)   // if current sum is greter than maximum sum so far
    {
        maxsum = left+right+root->val;  //we are adding all 3 values unlike returning, becz we're checking if current root is the final root
        node = root;
        leftSum = left;
        rightSum = right;
    }
    return max(left, right)+root->val;  //here we can't use all 3 values and neither we skip the root node, so that's why taking max of both the sides   
}

void getPath(TreeNode* curr_node, int sum, int sum_so_far, vector<int> path, vector<int> &completePath, int &flag)  // do a preorder traversal, and keep on adding value till we get the sum
{
    if (curr_node == NULL)
        return; 

    sum_so_far += curr_node->val;
    path.push_back(curr_node->val);

    if (sum_so_far == sum && (flag==0 || flag==1))  //flag = 0, means leftsubtree so reverse it 
    {
        if(flag==0)
            reverse(path.begin(), path.end());
        completePath.insert(completePath.end(), path.begin(), path.end());
        flag = 2;   //marking it to 2, to avoid adding multple paths
    }

    if (curr_node->left != NULL) 
        getPath(curr_node->left, sum, sum_so_far, path, completePath, flag); 

    if (curr_node->right != NULL)
        getPath(curr_node->right, sum, sum_so_far, path, completePath, flag); 
}