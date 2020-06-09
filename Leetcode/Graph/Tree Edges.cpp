/*  The basic idea is to find diameter in an undirected tree graph. 
    A naive solu could be to run dfs() from any random node and try to find out the farthest node from it, let's call it X. Then run another dfs() from X to get the final result.

    Optimized Solu: Is by running a single DFS()
    1. Our recursive dfs() function returns the length of the longest path of current node.
    2. In the process of traversing the child nodes of the current point, we find the maximum value and the second largest value of their recursive function return value plus 1.

 */

class Solution
{
    public:
    int treeDiameter(vector<vector<int>> & edges)
    {
        int n = edges.size()+1;
        graph.resize(n);

        for(auto &it: edges)
        {
            graph[it[0]].emplace_back(it[1]);
            graph[it[1]].emplace_back(it[0]);
        }

        diameter = 0;
        dfs(0, -1);

        return diameter;
    }

    private:
    vector<vector<int>> graph;
    int diameter;

    int dfs(int curr, int parent) 
    {
        int max1=0, max2=0;
        for(int v: graph[curr])
        {
            if(v != parent)
            {
                int temp = dfs(v, curr);
                if(temp>max1)
                {
                    max2=max1;
                    max1=temp;
                }
                else if(temp>max2)
                    max2=temp;
            }
        }
        diameter = max(diameter, max1+max2);

        return max1+1;
    }
};