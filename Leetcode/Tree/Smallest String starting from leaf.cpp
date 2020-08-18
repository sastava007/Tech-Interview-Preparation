/* 
    FInd the lexographically smallest string strting from leaf node to root node 
    TC: O(NlogN) becz we've to make comparisons

    Edge Case: 
            e
          /   \
         a     b
        /
       b

    Output(if I'm solving top-bottom) = bae
    Oterwise if I'm solving bottom-top then = be which is wrong
*/

class Solution {
public:
    string smallestFromLeaf(TreeNode* root) 
    {
        return util(root, "");
    }
    string util(TreeNode* root, string res)     // top-bottom approach, keep on adding the elements on the fly as you go deep
    {
        if(root==NULL)
            return res;
        
        string temp(1, 'a'+root->val);
        res = temp + res;
        
        if(!root->left && !root->right)
            return res;
        if(!root->left || !root->right)
            return (root->left==NULL)?util(root->right, res):util(root->left, res);
        
        string left = util(root->left, res);
        string right = util(root->right, res);
        
        return left<right?left:right;
    }
};

