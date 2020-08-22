/* 
    Find the cheapest flight from src->dst with atmost K stops.
    This problem sounds similar to a Dijkstra algo, but here we don't maintain the global optimal distance to each node i.e if(dist[v] > dist[u] + weight) => dist[v] = dist[u] + weight

    Becz there could be routes which has shorter path but has more stops. To deal with this, rather than maintaining optimal routes with 0..K stops for each node, the solution simply put all possible routes into the priority queue, so that all of them has a chance to be processed.

    TC: O(E + ElogV) here O(E) for making the graph from edges[] & Space: O(V+E)
*/

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) 
{
    vector<vector<pair<int, int>>> graph(n);
    
    for(auto flight: flights)
        graph[flight[0]].push_back({flight[1], flight[2]});
    
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    
    pq.push({0, {src, 0}});
    
    while(!pq.empty())
    {
        auto temp = pq.top();
        pq.pop();
        
        int cost = temp.first, city = temp.second.first, stops = temp.second.second;
        
        if(city == dst)
            return cost;
        if(stops <= K)
        {
            for(auto it: graph[city])
            {
                pq.push({cost+it.second, {it.first, stops+1}});
            }
        }
    }
    return -1;
}