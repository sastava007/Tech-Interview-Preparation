/* Given undirected graph, and it doesn't contain any back edges and selfloops */

void util(int v, vector<int> g[], unordered_set<int> &visited, vector<int> &result)
{
    result.push_back(v);
    visited.insert(v);
    
    for(int neigh: g[v])
        if(visited.find(neigh)==visited.end())
            util(neigh, g, visited, result);
    
}

vector <int> dfs(vector<int> g[], int N)
{
    unordered_set<int> visited;
    vector<int> result;
    
    for(int i=0; i<N; i++)
        if(visited.find(i)==visited.end())
            util(i, g, visited, result);
    
    return result;

}