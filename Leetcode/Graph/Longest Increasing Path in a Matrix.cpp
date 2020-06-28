/*  
    Find the length of maximum (strictly)increasing path in a matrix

    DFS + Memoization:    TC:  O(M*N) and Space:  O(M*N)
    
    So idea is to run a DFS from every cell in matrix, which will return the maximum increasing possible path length from that starting from that particular cell.
    And we should also cache the result obtained for each cell, becz this may be the case that same cell may be called multple times so it's better to store the result when we encounter
    for the first time, and whenever we reach that cell again simply return the max path length possible.

    And the answer would be maximum of each cell

*/

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) 
    {
        if(matrix.size() == 0)
            return 0;
        int n = matrix.size(), m = matrix[0].size(), maxlen = 1;
        vector<vector<int>> cache(n, vector<int>(m, 0));
        
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                maxlen = max(maxlen, dfs(matrix, cache, i, j));
        
        return maxlen;
    }
private:
    vector<pair<int,int>> dirs = {{-1,0}, {0,1}, {1,0}, {0,-1}};
    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& cache, int x, int y)
    {
        if(cache[x][y] != 0)    // if already visitd that point, then return the path length from cache no need to call the DFS again
            return cache[x][y];
        
        int n = matrix.size(), m = matrix[0].size();
        
        for(auto &it: dirs)
        {
            int xx = x+it.first, yy = y+it.second;
            if(xx<0 || xx>=n || yy<0 || yy>=m || matrix[xx][yy]<=matrix[x][y])
                continue;
            cache[x][y] = max(cache[x][y], dfs(matrix, cache, xx, yy));
        }
        return ++cache[x][y];   // incrementing by 1 for the current element, in addition for all the neighbouring cells that may be increasing but adding 1 for current cell
    }
};