/* TC: O(N) and Space: O(width_of_BT) */

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
public class Solution {
    public List<Integer> largestValues(TreeNode root) {
        List<Integer> res = new ArrayList<Integer>();
        helper(root, res, 0);
        return res;
    }
    private void helper(TreeNode root, List<Integer> res, int d){
        if(root == null){
            return;
        }
       //expand list size
        if(d == res.size()){
            res.add(root.val);
        }
        else{
        //or set value
            res.set(d, Math.max(res.get(d), root.val));
        }
        helper(root.left, res, d+1);
        helper(root.right, res, d+1);
    }
}