
class Solution{
public:
    vector<vector<int>> transitiveClosure(int N, vector<vector<int>> graph)
    {
        // code here
        for(int i=0; i<N; i++) graph[i][i] = 1;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                for(int k=0; k<N; k++){
                    graph[j][k] |= graph[j][i] & graph[i][k];
                }
            }
        }
        
        return graph;
    }
};
