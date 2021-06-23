/*
Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.


*/

class Solution {
public:
   
   
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int r = matrix.size();
    if (r == 0)
        return matrix;
    int c = matrix[0].size();
    vector<vector<int> > dp(r, vector<int>(c, INT_MAX - 100000));

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (matrix[i][j] == 0)
                dp[i][j] = 0;
            else {
                if (i > 0)
                    dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
                if (j > 0)
                    dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
            }
        }
    }

    for (int i = r - 1; i >= 0; i--) {
        for (int j = c - 1; j >= 0; j--) {
            if (i < r - 1)
                dp[i][j] = min(dp[i][j], dp[i + 1][j] + 1);
            if (j < c - 1)
                dp[i][j] = min(dp[i][j], dp[i][j + 1] + 1);
        }
    }

    return dp;
    }
};


/*
0 0 0
0 1 0
1 1 1

*/
