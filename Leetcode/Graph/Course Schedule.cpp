/*  The problem is equivalent to finding the cycle in a directed graph, we can use a BFS to implement topological sorting.

    If [v,u] course u is a prerequisite of course v, then the adjacency list of u will contain v.
    Also maintain vector containing the indegree of course, so the course which have indegree = 0, means we can start from that course. If we don't have any such course, then means deadlock
 
    TC: O(V+E) and Space: O(V+E)
 */

class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) 
    {
        vector<vector<int>> graph(n, vector<int>());
        vector<int> indegree(n, 0);
        
        for(auto &it: prerequisites)
        {
            graph[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }
        
        queue<int> q;
        for(int i=0; i<n; i++)
            if(indegree[i]==0)
                q.push(i);
        
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            n--;
            for(auto &next: graph[curr])
            {
                if(--indegree[next]==0)
                    q.push(next);
            }    
        }
        return (n==0);
    }
};

/* DFS to check is there exists cycle by implementing Graph Coloring */

bool canFinish(int n, vector<vector<int>>& pre) 
{
    vector<int> adj[n];
    for(auto edge : pre)
        adj[edge[1]].push_back(edge[0]);

    vector<int> colors(n,0);        // color 0 means unvisited
    
    for(int i=0;i<n;i++)
    {
        if(iscycle(adj, colors, i))
            return false;
    }
    return true;
}

bool iscycle(vector<int> adj[], vector<int> &colors, int v)
{
    if(colors[v] == 1)      // if this vertex has already been visited i.e marked with 1 which means a cycle exists and that's why we reached at same node again
        return true;

    if(colors[v] == 0)      // if unvisited node, then mark it visited and recursively traverse for it's neighbours 
    {
        colors[v] = 1;
        for(int negh: adj[v])
        {
            if(iscycle(adj, colors, negh))
                return true;
        }
    }
    colors[v] = 2;
    return false;
}