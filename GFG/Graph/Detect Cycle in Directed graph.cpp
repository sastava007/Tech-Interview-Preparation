/*  
    So here idea is to use graph coloring to mark the vertices.
    color 0 - vertex isn't yet processed
    color 1 - vertex is being processed (DFS for this vertex has started, but not finished which means that all descendants of this vertex are not processed yet)
    color 2 - vertex is completely processed

    So while exploring the vertices, if we find a vertex which is 1 (i.e it is also in processing state) then it means there exist cycle. If the graph has cycle then all the grey nodes are
    part of cycle, so we can also print them if we want.

    TC: O(V+E) & Space: O(V)
*/

bool isCyclic(int v, vector<int> adj[])
{
    int colors[v]={0};  // 0: means unvisited node
    
    for(int i=0; i<v; i++)
    {
        if(colors[i]==0)
            if(hasCycle(i, adj, colors))
                return true;
    }
    return false;
}
bool hasCycle(int v, vector<int> adj[], int colors[])
{
    colors[v]=1;
    
    for(int neigh: adj[v])
    {
        if(colors[neigh]==1)
            return true;
        if(colors[neigh]==0 && hasCycle(neigh,adj,colors))
            return true;
    }
    colors[v] = 2;
    return false;
}

