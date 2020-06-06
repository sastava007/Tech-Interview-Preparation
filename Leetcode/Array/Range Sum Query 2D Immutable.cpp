/* sums[i+1][j+1] represents the sum of area from (0,0) to (i+1,j+1) 
    Preprocessing Time: O(mn), Space Complexity: O(mn)
    Query Time: O(1) per query
*/

class NumMatrix 
{
public:
    int row, col;
    vector<vector<int>> sums;
    
    NumMatrix(vector<vector<int>>& matrix) 
    {
        row = matrix.size();
        col =row>0? matrix[0].size() : 0;
        
        sums = vector<vector<int>>(row+1, vector<int>(col+1, 0));
        
        for(int i =1; i<=row; i++)
            for(int j =1; j<=col; j++)
            {
                sums[i][j] = sums[i-1][j]+sums[i][j-1]-sums[i-1][j-1]+matrix[i-1][j-1];
            }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) 
    {
        //make sure to check asked range is <= boundary condition of matrix
        row1=min(row1, row-1);
        row2=min(row2,row-1);

        col1=min(col1, col-1);
        col2=min(col2, col-1);

        return sums[row2+1][col2+1]-sums[row2+1][col1]-sums[row1][col2+1]+sums[row1][col1];
    }
};