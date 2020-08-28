/* 
    Given a matrix, we've to find minimum sum of a falling path.
    A falling path starts from any element in first row, and chooses one element in each row. The next row choice must be in a column
    that is different from the previous rows column.

    dp[i][j] = min(dp[i+1][j], dp[i+1][j-1], dp[i+1][j+1]) + matrix[i][j]

    But in below code we've implemented starting from 0th row and going toward down, if we follow above case then we've to start from n-1 row and come towards top
*/


int minFallingPathSum(vector<vector<int>>& A) 
{
    vector<vector<int>> dp(A.size(), vector<int>(A[0].size(), INT_MAX));
    
    for(int j=0; j<A[0].size(); j++)    // Initialize the DP matrix
        dp[0][j] = A[0][j];

    for(int i=1; i<A.size(); i++)
        for(int j=0; j<A[0].size(); j++)
        {
            dp[i][j] = min({dp[i-1][j], dp[i-1][(int)max(0,j-1)], dp[i-1][min((int)A[0].size()-1, j+1)] }) + A[i][j];   
            
        }
    
    int ans = INT_MAX;
    for(int j=0; j<A[0].size(); j++)
        ans = min(ans, dp[A.size()-1][j]);
    
    return ans;
}