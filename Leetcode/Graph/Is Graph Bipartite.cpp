/*  The idea is to check if it's possible to color graph with 2 colors
    Even cycle length => Yes it's possible | Odd cycle lebgth => Not possible
    Explore node using DFS, and mark the color of current node and it's children with opposite colors. And if we reach at a node such that it visited and
    it's color and it's child color is same then return false.

    To avoid missing any vertex in case graph isn't connected we are iterating over vertices lineraly
*/

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) 
    {
        int n = graph.size();
        colors.resize(n, -1);
        
        for(int i = 0; i<n; i++)
        {
            if(colors[i] == -1)
            {
                if(!isBipartiteUtil(graph, i, 0))
                    return false;
            }
        }
        
        return true;
    }
    
    private:
    vector<int> colors;
    bool isBipartiteUtil(vector<vector<int>> &graph, int v, int c)
    {
        colors[v] = c;
        
        for(int child: graph[v])
        {
            if(colors[child] == -1)     //vertex is not yet visited
            {
                if(isBipartiteUtil(graph, child, !c) == false)
                    return false;
            }
            else
                if(colors[v] == colors[child])
                    return false;
        }
        return true;
    }
};