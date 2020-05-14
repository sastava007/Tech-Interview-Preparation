/*  LC: https://leetcode.com/problems/sum-root-to-leaf-numbers/
    Idea, is simple to do a preorder traversal and keep adding the numbers once we reach a leaf node
*/

class Solution 
{
public:
    int sumNumbers(TreeNode* root) 
    {
        int ans = 0;
        if(root==NULL)
            return ans;
        util(root, "", ans);
        return ans;
    }
    
private:
    void util(TreeNode* root, string s, int &ans)
    {
        if(root==NULL)
            return;
        
        s += to_string(root->val);
        
        if(!root->left && !root->right)
        {
            ans += stoi(s);         //This makes the operation costly, becz stoi() is in linear complexity in itself so overall solution becomes O(N2)
            return;
        }
        
        util(root->left, s, ans);
        util(root->right, s, ans); 
    }
};

/* Ideal Solu: It uses concept of units/tense places */

class Solution {
public:
    int sumNumbers(TreeNode* root) 
    {
        int ans = 0;
        if(root==NULL)
            return ans;
        
        return util(root, 0);
    }
    
private:
    int util(TreeNode* root, int val)
    {
        if(root==NULL)
            return 0;
        
        val = val*10 + root->val;
        
        if(!root->left && !root->right)
            return val;
        
        int left = util(root->left, val);
        int right = util(root->right, val);
        
        return left+right;
    }
};