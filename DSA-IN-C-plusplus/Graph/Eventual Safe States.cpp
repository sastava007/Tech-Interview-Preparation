class Solution {
  public:
     vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        vector<int> inDegree(V, 0);
        unordered_map<int, list<int>> revAdj;
        
        for(int i=0; i<V; i++){
            for(int j=0; j<adj[i].size(); j++){
                inDegree[i] = adj[i].size();
                revAdj[adj[i][j]].push_back(i);
            }
        }
        
        queue<int> q;
        
        for(int i=0; i<V; i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }
        vector<int> safeNodes;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            safeNodes.push_back(node);
            
            for(auto nbr: revAdj[node]){
                inDegree[nbr]--;
                if(inDegree[nbr] == 0){
                    q.push(nbr);
                }
            }
        }
        
        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }
};
