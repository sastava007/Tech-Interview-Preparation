/* TC: O(N) and Space: O(maximum_width_of_BT) */

class Solution {
public:
    vector<int> largestValues(TreeNode* root) 
    {
        vector<int> result;
        if(root==NULL)
            return result;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            int size = q.size(), max_ele = INT_MIN;
            while(size--)
            {
                TreeNode* temp = q.front();
                q.pop();        
                max_ele = max(max_ele, temp->val);
                if(temp->left)
                    q.push(temp->left);
                
                if(temp->right)
                    q.push(temp->right);
            }
            result.emplace_back(max_ele);
        }
        return result;
    }
};

/* Using recusive DFS */
class Solution 
{
    vector<int> solution;
public:
    void helper(TreeNode* node, int cl)
    {
        if (node == NULL) {
            return;
        }
        if (solution.size() < cl + 1) {
            solution.push_back(node->val);
        } else {
            if (solution[cl] < node->val) {
                solution[cl] = node->val;
            }
        }
        helper(node->left, cl+1);
        helper(node->right, cl+1);
    }
    vector<int> largestValues(TreeNode* root)
    {
        if(root == NULL) {
            return solution;
        }
        
        helper(root, 0);
        return solution;
    }
};