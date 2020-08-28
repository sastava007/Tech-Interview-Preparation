/* 
    Given a grid, find the minimum path sum to reach the bottom most right corner from top left corner.
    Using DP:

    Minimum path sum to reach the point (i.j) will be min of path from top and left hence we get this dp relation dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j]
*/

int minPathSum(vector<vector<int>>& grid) 
{
    if(grid.size() == 0 || grid[0].size()==0)
        return 0;
    int m = grid.size(), n = grid[0].size();
    
    vector<vector<int>> dp(m, vector<int>(n));
    dp[0][0] = grid[0][0];
    
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
        {
            if(i==0 && j>0)
            {
                dp[i][j] = dp[i][j-1] + grid[i][j];
            }
            else if(j==0 && i>0)
            {
                dp[i][j] = dp[i-1][j] + grid[i][j];
            }
            else if(i>0 && j>0)
            {
                dp[i][j] = min(dp[i][j-1], dp[i-1][j]) + grid[i][j];    
            }
        }
    return dp[m-1][n-1];
}

/* 
    Optimized: O(N) Space
    Upon obervation we can see that we only need two columns and not the entire matrix. And upon further optimization we can see solve this using a single array 
    as dp[i] will represent path sum to reach (i,n-1). So we only need to find the dp[m-1]
*/

int minPathSum(vector<vector<int>>& grid) 
{
        int m = grid.size(), n = grid[0].size();
        vector<int> dp(m, grid[0][0]);
        for (int i = 1; i < m; i++)
            dp[i] = dp[i - 1] + grid[i][0];

        for (int j = 1; j < n; j++) 
        {
            dp[0] += grid[0][j]; 
            for (int i = 1; i < m; i++)
                dp[i] = min(dp[i - 1], dp[i]) + grid[i][j];     // only need current and past row
        }
        return dp[m - 1];
}