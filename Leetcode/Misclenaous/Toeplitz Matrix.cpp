class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) 
    {
        for(int i=0; i<matrix.size()-1; i++)
        {
            for(int j=0; j<matrix[i].size()-1; j++)
                if(matrix[i][j] != matrix[i+1][j+1])    // can also be checked for top-left i.e matrix[i-1][j-1] 
                    return false;
        }
        
        return true;
    }
};

/*  Follow Up: If matrix is so large, that we can only load 1 row at a time in memory then we can use a hash-map to record the current element to r-c. And later for next row check
    whether this equals to value set by previous row or not.

*/

public boolean isToeplitzMatrix(int[][] matrix) 
{
    Map<Integer, Integer> groups = new HashMap();
    for (int r = 0; r < matrix.length; ++r) {
        for (int c = 0; c < matrix[0].length; ++c) {
            if (!groups.containsKey(r-c))
                groups.put(r-c, matrix[r][c]);
            else if (groups.get(r-c) != matrix[r][c])
                return False;
        }
    }
    return True;
}