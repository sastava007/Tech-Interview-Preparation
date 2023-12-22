// User function Template for C++

class Solution {
  public:
    int sumOfDependencies(vector<int> adj[], int V) {
        // code here
        int res = 0;
        for(int i=0; i<V; i++){
            res+=adj[i].size();
        }
        
        return res;
    }
};
