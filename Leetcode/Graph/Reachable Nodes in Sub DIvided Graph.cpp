/*  
    Inititally we were given edges (i,j) in b/w which 'n' new nodes are inserted which lead to a path length of (n+1) in b/w two nodes. We've to find the no. of nodes
    that we can reach starting from '0' in atmost M moves.

    It can be solved using Dijkstra, first find the shortest path length to each node starting from '0' and then check if this dist[node] <= M then increment the counter.
    Later for the new nodes lying in b/w (i, j) can be computes using a smart trick.

*/

class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int M, int N) 
    {
        vector<vector<pair<int, int>>> graph(N);
        for(auto it: edges)
        {
            graph[it[0]].push_back({it[1], it[2]+1});   // undirected graph
            graph[it[1]].push_back({it[0], it[2]+1});
        }
        
        vector<int> dist(N, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push({0, 0});
        dist[0] = 0;
        
        while(!q.empty())
        {
            auto temp = q.top();
            q.pop();
            
            for(auto it: graph[temp.second])
            {
                int u = temp.second, v = it.first, w = it.second;
                if(dist[v] > dist[u] + w)
                {
                    dist[v] = dist[u] + w;
                    q.push({dist[v], v});
                }
            }
        }
        
        int res = 0;
        for(int i=0; i<N; i++)  // find the original nodes which are reachable from src(0)
            if(dist[i] <= M)
                res++;
        
        for(auto it: edges)
        {
            
            int a = dist[it[0]]>=M?0:min(M-dist[it[0]], it[2]); // no. of new nodes that we can reach while going from it[0]->it[1]
            int b = dist[it[1]]>=M?0:min(M-dist[it[1]], it[2]); // no. of new nodes that we can reach while going from it[1]->it[0]
            
            res += min(a+b, it[2]);     // to remove to nodes that are counted twice
        }
        return res;
    }
};