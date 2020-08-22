/* 
    Classical Dijkstra Problem:

    How long time will it take for all the nodes to receive the signal starting from the source node, basically we're suppose to find maximum path value using Dijkstra algo.
    TC: O(E + ElogV) here O(E) for making the graph from edges[] & Space: O(V+E)
    
    Note: All the edge weight is +ve
*/

int networkDelayTime(vector<vector<int>>& times, int N, int K) 
{
    vector<vector<pair<int, int>>> graph(N+1);
    for(auto it: times)
        graph[it[0]].push_back({it[1], it[2]});
    
    vector<int> dist(N+1, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    
    q.push({0, K});
    dist[K] = 0;
    
    while(!q.empty())   // We can also use a bool visited[] but there's no need of it, as Dijkstra is a greedy algo. So each time we check (dist[v] > dist[u] + w) will help
    {                                   // to eliminate the use of visited[]
        auto temp = q.top();
        q.pop();
        
        for(auto it: graph[temp.second])
        {
            int u = temp.second, v = it.first, w = it.second;
            if(dist[v] > dist[u]+w)
            {
                dist[v] = dist[u]+w;
                q.push({dist[v], v});
            }
        }
    }
    int maxDelay = 0;
    for(int i=1; i<=N; i++)
    {
        if(dist[i]==INT_MAX)
            return -1;
        maxDelay = max(maxDelay, dist[i]);
    }
    return maxDelay;
}

/* 
    If edge weight can be -ve, then in that case we'll use Bellman Ford 
    TC: O(V*E)
*/

int networkDelayTime(vector<vector<int>>& times, int N, int K) 
{
    vector<int> dist(N+1, INT_MAX);
    dist[K] = 0;
    
    for(int i=0; i<N; i++)
        for(auto edge: times)
        {
            int u = edge[0], v = edge[1], w = edge[2];
            
            if(dist[u] != INT_MAX && dist[v]>dist[u]+w)
                dist[v] = dist[u] + w;
        }
    
    int maxWeight = 0;
    for(int i=1; i<=N; i++)
    {
        if(dist[i]==INT_MAX)
            return -1;
        
        maxWeight = max(maxWeight, dist[i]);
    }
    return maxWeight;
}