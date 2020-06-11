/* At each node we can check if the subtree rooted under the current node(childrens) has any apples if it does we add the distance from current node to that child node and we return this distance else we return 0.
    The other key observation is that each time we collect the apple we have to walk back to the parent, thus the distance travelled is doubled. 
*/

class Solution {
private:
    vector<vector<int>> graph;
    
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) 
    {
        graph.resize(n);
        
        for(auto &it: edges)
        {
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }
        
        return (dfs(hasApple, 0, 0, -1)*2);     // HERE D MEANS THE DISTANCE FROM THE ROOT NODE
    }
    
private:
    int dfs(vector<bool> &hasApple, int node, int d, int prev)  //here d means depth from root node
    {
        int result = 0, temp;
        for(int &v: graph[node])    //traverse all it's children
        {
            if(v!=prev) //if not yet visited
            {
                temp = dfs(hasApple, v, d+1, node);
                if(temp)
                    result += temp-d;   // if a child has apples then it will result a non zero result, which represents the distance b/w child node and root node. Wwe're subtracting becz we're getting distance from root node each time, So dist() b/w two nodes is by subtracting
                
            }
        }
        
        return (result || hasApple[node]?result+d:0);
    }
};