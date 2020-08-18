/*
    We know that first element of preorder[] is root node, so let's say if position of this element in inorder[] is "i" then all the elements before "i" will be 
    part of left subtree and all the elements after "i" will be part of right subtree.

    preorder = [3,9,20,15,7]    inorder = [9,3,15,20,7]

    PS: We've assumed here that there's no duplicate value
*/

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& iorder) 
    {
        unordered_map<int, int> inorder;
        for(int i=0; i<iorder.size(); i++)
            inorder[iorder[i]] = i;
        
        return util(0, 0, iorder.size()-1, preorder, inorder); 
    }
    TreeNode* util(int pstart, int istart, int iend, vector<int> &preorder, unordered_map<int,int> &inorder)
    {
        if(pstart >= preorder.size() || istart > iend)
            return NULL;
        
        TreeNode* root = new TreeNode(preorder[pstart]);
        
        int index = inorder[root->val];
        
        root->left = util(pstart+1, istart, index-1, preorder, inorder);
        root->right = util(pstart+index-istart+1, index+1, iend, preorder, inorder);   // index-istart is size of left subtree, so to get first element of right subtree we've skip these elements
        
        return root;
    }
};

/* 
    O(N) Solution: Without using Map 
    So, instead of splitting the arrays and recursing on them, just recurse on the full remaining array and stop when you come across first element of preorder[] in inorder[]
    
*/
class Solution
{
    private int in = 0;
    private int pre = 0;
    
    public TreeNode buildTree(int[] preorder, int[] inorder)
    {
        return build(preorder, inorder, Integer.MIN_VALUE);
    }
    private TreeNode build(int[] preorder, int[] inorder, int stop) 
    {
        if (pre >= preorder.length) return null;
        if (inorder[in] == stop)
        {
            in++;
            return null;
        }

        TreeNode node = new TreeNode(preorder[pre++]);
        node.left = build(preorder, inorder, node.val);
        node.right = build(preorder, inorder, stop);
        return node;        
    }
}