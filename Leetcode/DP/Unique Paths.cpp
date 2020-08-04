/* 
    Given a [M X N] grid, find the no. of ways to reach the bottom most cell from top left if we can only move in right and down direction.
    No of ways to reach cell (i,j) will be equal to sum of ways to reach from it's left and top dp[i][j] = d[i-1][j] + dp[i][j-1]
*/

int uniquePaths(int m, int n) 
{
    if(m == 0 || n ==0)
        return 1;
    
    vector<vector<int>> dp(m, vector<int>(n, 1));
    
    for(int i=1; i<m; i++)
        for(int j=1; j<n; j++)
        {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    
    return dp[m-1][n-1];
}

/* 
    When we update dp[i][j], we only need dp[i - 1][j](it's previous row) and dp[i][j - 1](it's current row). So we can reduce the memory usage to just two rows O(n) 
*/

int uniquePaths(int m, int n) 
{
    vector<int> pre(n, 1), cur(n, 1);
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++) {
            cur[j] = pre[j] + cur[j - 1];
        }
        swap(pre, cur);
    }
    return pre[n - 1];
}

/* Further inspecting the above code, pre[j] is just the cur[j] before the update. So we can further reduce the memory usage to one row. */

int uniquePaths(int m, int n)
{
    vector<int> cur(n, 1);
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++) {
            cur[j] += cur[j - 1];
        }
    }
    return cur[n - 1];
}