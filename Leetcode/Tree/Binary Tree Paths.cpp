/*  Store all the paths from root to leaf node 
    TC: O(N) and Space: O(H) in worst case(skewed) O(N)
*/

class Solution {
public:
    
    vector<string> path;
    vector<string> binaryTreePaths(TreeNode* root) 
    {
        if(root==NULL)
            return path;

        util(root, "");
    
        return path;
    }

    void util(TreeNode* root, string s)
    {
        if(root==NULL)
            return;
        
        s += to_string(root->val);
        
        if(!root->left  && !root->right)
            path.emplace_back(s);
        
        util(root->left, s + "->");
        util(root->right, s + "->");   
    }
};


/* Iterative Solution */
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (root == NULL) return res;
        stack<TreeNode*> s;
        stack<string> pathStack;
        s.push(root);
        pathStack.push(to_string(root->val));
        
        while (!s.empty()) {
            TreeNode * curNode = s.top(); s.pop();
            string tmpPath = pathStack.top(); pathStack.pop();
            
            if (curNode->left == NULL && curNode->right == NULL) {
                res.push_back(tmpPath); continue;
            }
            
            if (curNode->left != NULL) {
                s.push(curNode->left);
                pathStack.push(tmpPath + "->" + to_string(curNode->left->val));
            }
            
            if (curNode->right != NULL) {
                s.push(curNode->right);
                pathStack.push(tmpPath + "->" + to_string(curNode->right->val));
            }
        }
        
        return res;
    }
};