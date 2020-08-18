/* 
    Find bridge (edges) of a graph upon removal of which the number of connected components will increase. Or some vertex can not reach the other some vertex
    TC: O(V+E)

    The current edge (u,v) is a bridge if and only if none of the vertices 'v' and its descendants in the DFS traversal tree has a back-edge to vertex 'u' or any of its ancestors.
    Basically an edge is a bridge if & only if it is not in a cycle.

    If low[child] <= in[node] this means that 'child' is connected to an ancestor of 'node' becz of which 

    https://cp-algorithms.com/graph/bridge-searching.html

*/

class Solution {
private:
    vector<int> in, low;
    vector<bool> visited;
    int timer;
    
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) 
    {
        vector<vector<int>> adj(n), result;
        for(int i=0; i<connections.size(); i++)     // build the graph from given set of connections/edges
        {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        timer = 0;
        visited.assign(n, false);
        in.assign(n, -1);  low.assign(n, -1);
        
        for(int i=0; i<n; i++)
        {
            if(!visited[i])
                dfs(result, adj, i);
        }
        return result;
    }
    void dfs(vector<vector<int>> &result, vector<vector<int>> &adj, int v, int p = -1)
    {
        visited[v] = true;
        in[v] = low[v] = timer++;
        for(int neigh: adj[v])
        {
            if(neigh == p)
                continue;
            if(visited[neigh])  // this means their's is a back edge
                low[v] = min(low[v], in[neigh]);
            else
            {
                dfs(result, adj, neigh, v);
                low[v] = min(low[v], low[neigh]);
                if(low[neigh] > in[v])
                    result.push_back(vector<int>({v, neigh}));
            }
        }
    }
};