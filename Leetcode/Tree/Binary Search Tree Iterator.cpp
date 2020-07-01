/*  
    Expected TC: O(1) average(amortized) time per query(). Though it looks like that when we call for right child it will process N nodes, but it will not process N nodes always. 
    They will be much lesser. So avergae TC will be O(1)
    
    Space complexity: O(h) or O(logN) ~ Height of binary Tree, So we have to perform controlled recursion instead of just storing the inorder traversal in a vector which will require O(N) space
*/

#include<bits/stdc++.h>
using namespace std;

class BSTIterator {
private:
    stack<TreeNode*> s;
public:
    BSTIterator(TreeNode* root)
    {
        left_inorder(root);
    }
    int next() 
    {
        TreeNode* node = s.top();
        s.pop();
        
        if(node->right)
            left_inorder(node->right);
        
        return node->val;
    }
    bool hasNext() 
    {
        return (!s.empty()); 
    }
private:
    void left_inorder(TreeNode* root)
    {
        TreeNode* node = root;
        while(node)
        {
            s.push(node);
            node=node->left;
        }
    }
};