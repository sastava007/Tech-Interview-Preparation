class Solution
{
private:
     map<Node*, Node*>parent;
        Node* tar;
        vector<int>ans;
public:

   
    
    void findParent(Node* root, int target, Node* p){
        if(root == NULL) return;
        parent[root] = p;
        if(root->data == target) tar = root;
        findParent(root->left, target, root);
        findParent(root->right, target, root);
    }
     
    void solve(Node* node, int dis, Node* prev){
        if(node == NULL) return;
        if(dis == 0){
            ans.push_back(node->data);
            return;
        }
        if(node->left != prev)
        solve(node->left, dis-1, node);
        
        if(node->right != prev)
        solve(node->right, dis-1, node);
        
        if(parent[node] != prev)
        solve(parent[node], dis-1, node);
    }
    
    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
        // return the sorted vector of all nodes at k dist
        parent.clear();
        ans.clear();
        findParent(root , target, NULL);
       
        solve(tar, k, NULL);
        sort(ans.begin(), ans.end());
        return ans;
    }
};
