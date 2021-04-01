/* 
    Given a BST with duplicates find the modes(max occurring), and if there are more than 1 then return all the modes.

    Approach1:
        Using a hash-map and maintaining a counter value for all the nodes. TC would be O(N) and requires auxilarry space of O(N)
        other than the implict stack space (doesn't count).
    Approach2:
        Do inorder traversal and maintain a array/ vector of modes on the fly, keep on adding elements/ erase previous array if theier freq > maxFreq so far.
        The vector contents aren't on stack space, so it can't be disregarded that way. And if the values are for example 1,2,3,4,...,n-2,n-1,n-1 (unique values followed by one double value),
        the vector grows to Ω(n) and it can't be disregarded because the result only has size 1.
    Approach3:
        Use 2 pass solution, first find the maximum freq/occurrence of any value then again do inorder traversal to store all the nodes with same freq.

    Pro tip: We can also use a Morris traversal 

 */

class Solution {
private:
    TreeNode* prev = NULL;
    vector<int> ans;
    int currCount = 0, maxCount = 0;
public:
    vector<int> findMode(TreeNode* root) 
    {
        if(!root)
            return ans;
        inorder(root, false);
        
        prev = NULL;
        currCount = 0;
        
        inorder(root, true);
        return ans;
    }
    
    void inorder(TreeNode* root, bool getList)
    {
        if(!root)
            return;
        
        inorder(root->left, getList);
        
            if(prev && prev->val == root->val)
                currCount++;
            else
                currCount = 1;
            
            if(!getList)
                maxCount = max(maxCount, currCount);
            else if(currCount == maxCount)
                ans.emplace_back(root->val);
            prev = root;

        inorder(root->right, getList);
    }
};