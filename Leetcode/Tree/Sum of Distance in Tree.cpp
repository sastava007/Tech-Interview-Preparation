/* 
    We're given an undirected tree, and we've to return a list of distance where ans[i] represents the sum of distance of node 'i' to all other nodes.
    A naive solution will require running DFS from eam node and finding the sum of distance from each node, this will have total TC: O(N^2)

    Upon observing we can see that, if we shift/move our root node from one node to another then there will be few 'x' nodes which will become closer to it and remaining 'N-x' nodes
    farther from it. We can use this observation to solve the problem.

    1. First run a DFS from any node, which find the count[] / number of nodes in the subtree of root node and res[] which shows sum of distance of other nodes from it.
    2. Run another DFS to adjust the res[]

    https://github.com/tyqi11/leetcode/blob/master/834_Sum_of_Distances_in_Tree.java
*/

class Solution {
    
    vector<unordered_set<int>> tree;
    vector<int> count, res;
    
public:
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) 
    {
        tree.resize(N);
        res.assign(N, 0);        // sum of distance of all other nodes from current node
        count.assign(N, 1);     // no. of nodes rooted under current node
        
        for(auto it: edges)
        {
            tree[it[0]].insert(it[1]);
            tree[it[1]].insert(it[0]);
        }
        
        dfs(0, -1);
        dfs2(0, -1); 
        return res;
    }
    void dfs(int root, int pre)
    {
        for(auto i: tree[root])
        {
            if(i == pre)
                continue;
            
            dfs(i, root);
            count[root] += count[i];    // no. of nodes rooted under current node += count[child]
            res[root] += res[i] + count[i];
        }
    }
    void dfs2(int root, int pre)
    {   
       for(auto i: tree[root])
        {
           if(i == pre)
                continue;

            res[i] = res[root] - count[i] + count.size() - count[i];    // res[i] = res[root] - x + (   N-x)
            dfs2(i, root);
        }
    }
};