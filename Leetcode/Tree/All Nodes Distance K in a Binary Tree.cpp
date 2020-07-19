/*  FInd all the nodes which are at a distnace K from the target/start node. So for this we can simply use a BFS, and keep on incrementing levels and when level = K, we'll return everything from 
    queue. But this requires access to parent for going upward, so first find parent of each node and stire it in a hash-table.

    TC: O(N) & Space: O(N) but this will not be efficient as have to tarverse the tree 2 times
*/

class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) 
    {
        getParent(root, NULL);
        unordered_set<TreeNode*> visited;
        
        queue<TreeNode*> q;
        q.push(target);
        visited.insert(target);
        
        int dist = 0;
        vector<int> result;
        
        while(!q.empty())
        {
            if(dist == k)
            {
                while(!q.empty())
                {
                    result.push_back(q.front()->val);
                    q.pop();
                }
                return result;
            }
            int size = q.size();   
            while(size--)
            {
                TreeNode* node = q.front();
                q.pop();
                if(node->left && visited.find(node->left)==visited.end())
                {
                    q.push(node->left);
                    visited.insert(node->left);
                }
                if(node->right && visited.find(node->right)==visited.end())
                {
                    q.push(node->right);
                    visited.insert(node->right);
                }
                TreeNode* p = parent[node];
                if(p!=NULL && visited.find(p)==visited.end())
                {
                    q.push(p);
                    visited.insert(p);
                }
            }
            dist++;
        }
        return result;
    }
private:
    unordered_map<TreeNode*, TreeNode*> parent;
    void getParent(TreeNode* node, TreeNode* p)
    {
        if(node==NULL)
            return;
        parent[node] = p;
        getParent(node->left, node);
        getParent(node->right, node);
    }
};


/* Without using Hash-Map   TC: O(N) and O(N) space */

class Solution {
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K)
    {
        vector<int> result;     // Note : Since target is always in the tree, we can do this.
				
        if( K == 0){
            result.pb(target.val); 
            return target; 
        }
        traverse(result, root, target, K, 0); 
        return result; 
    }

    int traverse(vector<int> &result, TreeNode* root, TreeNode* target, int k, int val)
    {
        if(root == null) 
            return 0; 
						
        if(val == k){       // val == k implies that we are at the k-th resultant child from the target
            result.pb(root.val); 
            return 0; 
        }
        int left = 0, right = 0; 
				
				// either we find the target or we have already found the target propagate val+1
        if(root.val == target.val || val > 0 ){
            left = traverse(result, root.left, target, k, val+1); 
            right = traverse(result, root.right, target, k, val+1); 
        }
				
        else {      // else propagate the 0
            left = traverse(result, root.left, target, k, val); 
            right = traverse(result, root.right, target, k, val); 
        }
	
        if(left == k || right == k) {        // If a node receives a K in return it is k-th distant parent from the the target.
            result.add(root.val); 
            return 0;
        }
				
        if(root.val == target.val){   // Target node must return 1 other must return 0 if their subtree doesnt have target.
            return 1; 
        }
				
        if(left > 0){           // If left or right is greater than 0 that means one of the subtree has the target. Propagate the new value in the other subtree. 
            traverse(result, root.right, target, k, left + 1);
        }
        if(right > 0){
            traverse(result, root.left, target, k, right+1);
        }
				
        if(left > 0 || right > 0)           // If the subtree has target, return the resultance from target +1 
            return left > 0 ? left + 1 : right + 1; 
					
        return 0;   // else return 0
    }
}