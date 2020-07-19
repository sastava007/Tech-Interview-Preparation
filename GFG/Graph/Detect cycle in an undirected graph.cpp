/* 
    There could be multiple connnected components, so run DFS from each node and check if any of the component has a cycle then return true.
    Maintain a parent variable long with visited set to keep track of the explored vertices so far.
    
    Time & Space: O(V+E)

*/

bool isCyclic(vector<int> adj[], int V)
{
    unordered_set<int> visited;
    for(int i=0; i<V; i++)
    {        if(visited.find(i)==visited.end())
        {
            if(hasCycle(i, -1, adj, visited))
                return true;
        }
    }
    return false;
}

bool hasCycle(int v, int p, vector<int> adj[], unordered_set<int> &visited)
{
    if(visited.find(v) != visited.end())
        return true;
        
    visited.insert(v);
    
    for(int neigh: adj[v])
    {
        if(neigh != p)
        {
            if(hasCycle(neigh, v, adj, visited))
                return true;
        }
    }
    return false;
}