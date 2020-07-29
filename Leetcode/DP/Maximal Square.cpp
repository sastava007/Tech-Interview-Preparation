/*  DP Solution
    Here dp[i][j] represents the side length of maximal square whose bottom right corner is the cell with index (i,j) in the original matrix

    For each '1' in original matrix, dp[i][j] = min(dp(i−1,j),dp(i−1,j−1),dp(i,j−1))+1  // adding 1 for current element

    TC & Space: O(M*N)
*/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) 
    {
        if(matrix.size()==0 || matrix[0].size()==0)
            return 0;
        
        int rows = matrix.size(), cols = matrix[0].size();
        vector<vector<int>> dp(rows+1, vector<int>(cols+1, 0));
        
        int ans = 0;
        
        for(int i=1; i<=rows; i++)
            for(int j=1; j<=cols; j++)
            {
                if(matrix[i-1][j-1] == '1')
                {
                    dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]})+1;
                    ans = max(ans, dp[i][j]);
                }
            }
        return ans*ans;
    }
};

/*  Space Optimized DP:  
    Actually each time when we update dp[i][j], we only need dp[i-1][j-1], dp[i-1][j](the previous row) and dp[i][j-1] (the current row). So we may just keep two rows.
*/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) 
    {
        if(matrix.size()==0 || matrix[0].size()==0)
            return 0;
        
        int rows = matrix.size(), cols = matrix[0].size();
        vector<int> dp(cols+1);
        
        int ans = 0, prev=0;
        
        for(int i=1; i<=rows; i++)
            for(int j=1; j<=cols; j++)
            {
                int temp = dp[j];
                if(matrix[i-1][j-1] == '1')
                {
                    dp[j] = min({dp[j], dp[j-1], prev})+1;
                    ans = max(ans, dp[j]);
                }
                else
                    dp[j]=0;
                
                prev = temp;
            }
        return ans*ans;
    }
};