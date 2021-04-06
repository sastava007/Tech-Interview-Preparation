/* 
    We know that first value in pre[] is root node, and pre[1] is the left child of root.
    Also if we observe we can find that the moment when pre[i] = post[j] this basically means that we've explore all the nodes in subtree of current
    root node i.e pre[i] and we don't need to add any further children to it and now we can start constructing another tree.

*/

class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) 
    {
        int preIndex = 0, postIndex = 0;
        if(pre.empty())
            return NULL;
        return util(pre, post, preIndex, postIndex);
    }
private:
    TreeNode* util(vector<int> &pre, vector<int> &post, int &preIndex, int &postIndex)
    {
        TreeNode* root = new TreeNode(pre[preIndex++]);
        if(root->val != post[postIndex])
            root->left = util(pre, post, preIndex, postIndex);
        if(root->val != post[postIndex])
            root->right = util(pre, post, preIndex, postIndex);
        
        postIndex++;
        return root;
    }
};