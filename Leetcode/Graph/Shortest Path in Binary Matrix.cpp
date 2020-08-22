/* 
    Find the shortest path length from top-left to bottom-right in a square grid where each cell is either empty(0) or blocked(1).

    1.  So, the first thing that jumps into my mind is to use DP, such thar dp[i][j] represents the length of the shortest path to from src to (i,j)
        if(grid[i][j] == 0) => dp[i][j] = 1  else dp[i][j] = INT_MAX

        and then dp[i][j] = min(all_eight_neighbors) + 1 but this would not work becz we're not calulating the cells in right order like to compute dp[1][2] we need dp[2][2]
        which is not yet calculated. That's what makes this different from other problem where DP can be used.

    2. Use BFS
 */

int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
{
    if(grid.size()==0 || grid[0].size()==0)
        return 0;
    if(grid[0][0]==1)
        return -1;
    
    int dist = 0;
    queue<pair<int, int>> q;
    q.push({0,0});
    
    vector<pair<int, int>> dirs = {{-1,0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
    
    while(!q.empty())
    {
        int size = q.size();
        dist++;
        while(size--)
        {
            auto temp = q.front();
            q.pop();
            
            if(temp.first == grid.size()-1 && temp.second == grid[0].size()-1)
                return dist;
            
            for(auto it: dirs)
            {
                int x = temp.first + it.first, y = temp.second + it.second;
                if(x>=0 && x<grid.size() && y>=0 && y<grid[0].size() && grid[x][y]==0)
                {
                    q.push({x,y});
                    grid[x][y] = 1;   // Mark visited to otherwise if may be possible that same node is getting enqueued every time
                }
            }
        }
    }
    return -1;
}