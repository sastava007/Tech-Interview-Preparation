/*  Find the length of the longest consecutive increasing sequence path. Here path should be from parent to child not and can't be opposite. 
    
    Idea is to perform a recursive pre-order traversal of tree, and for each node check if it's value is one greater than it's parent value then increment it's current length else reset
    the current length.

    TC: O(N) and Space: O(H)

    1
     \
      3
     / \
    2   4
         \
          5
    
    length = 3 [3>4>5] It can't be 2>3>4>5 becz parent-child ordering should be there
*/

class Solution {
public:
    int longestConsecutive(TreeNode * root) 
    {
        if(root==NULL)
            return 0;
        int ans = 0;
        util(root, 0, ans, root->val);
        return ans;
    }
private:
    void util(TreeNode* root, int curr, int &ans, int expected)
    {
        if(root==NULL)
            return;
            
        if(root->val == expected)
            curr++;
        else
            curr = 1;
        ans = max(ans, curr);
        
        util(root->left, curr, ans, root->val+1);
        util(root->right, curr, ans, root->val+1);
    }
};

/*  Find the length of the longest consecutive (monotonic)increasing/decreasing path, and this path can be of child-parent-child order not necesseraily parent-child unlike above problem. 

    Idea is to perform a postorder traversal while maintaining 2 variables, one which stores the length of longest consecutive increasing sequence path and other one stores the length of the longest consecutive decreasing path.
    And then for each node upadte the maximum path length as max(max_length_so_far, incr+decr-1)

    TC: O(N) and Space: O(H) ~~ O(N) worst case

             1
            / \
           2   0
          /
         3

         length = 4 [0>1>2>3]

           1
            \
             3
            / \
           2   4
                \
                5
        length = 4 [2>3>4>5]
*/

class Solution {
public:
    int longestConsecutive2(TreeNode * root) 
    {
        int ans = 0;
        auto dump = util(root, ans);
        return ans;
    }
private:
    pair<int, int> util(TreeNode* root, int &ans)
    {
        pair<int, int> curr = {0,0};
        
        if(root==NULL)
        {
            return curr;
        }
        int incr = 1, decr = 1;
        
        if(root->left)
        {
            curr = util(root->left, ans);
            if(root->val == root->left->val+1)          // indicates decreasing
                decr = curr.second+1;
            else if(root->val == root->left->val-1)     // indicates increasing
                incr = curr.first+1;
        }
        if(root->right)
        {
            curr = util(root->right, ans);
            if(root->val == root->right->val+1)
                decr = max(decr, curr.second+1);    // only involve the right subtree path if after adding it our overall path length get longer
            else if(root->val == root->right->val-1)
                incr = max(incr, curr.first+1);
        }
        ans = max(ans, incr+decr-1);
        curr = {incr, decr};
        return curr;
    }
};