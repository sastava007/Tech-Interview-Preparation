class Solution {
  public:
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int V, vector<pair<int,int>>edges) {
        // Code here
        vector<vector<int>> ans(V);
        
        for(auto i: edges){
            int u = i.first;
            int v = i.second;
            
            ans[u].push_back(v);
            ans[v].push_back(u);
        }
        
        return ans;
    }
};
