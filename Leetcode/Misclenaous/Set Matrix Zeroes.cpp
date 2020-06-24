/*  If an elememnt of matrix is 0, then set the entire row & column to 0 in O(1) space 

    Naive Approach: Is by storing all the [r,c] which are 0 into 2 different hash sets, and while doing the secnod pass set the cells of that row/column to zero.  Space: O(M+N)
    by checking if (row.find(i)!=row.end() || col.find(j)!=col.end()) => matrix[i][j] = 0

    Optimized: We can rather use the first cell of every row and column as a flag. This flag would determine whether a row or column has been set to zero or not. If first cell of any 
    row/column is zero, then set the entire row & column to zero. We can treat the 1st row/column seperately
*/

 
void setZeroes(vector<vector<int>>& matrix) 
{
    if(matrix.size()==0 || matrix[0].size()==0)
        return;

    bool isZeroCol = false;
    bool isZeroRow = false;
    
    int row = matrix.size(), col = matrix[0].size();

    for (int i = 0; i < row; i++) { //check the first column
        if (matrix[i][0] == 0) {
            isZeroCol = true;
            break;
        } 
    }
    for (int i = 0; i < col; i++) { //check the first row
        if (matrix[0][i] == 0) {
            isZeroRow = true;
            break;
        } 
    }
    for (int i = 1; i < row; i++) { //check except the first row and column
        for (int j = 1; j < col; j++) 
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
    }
    for (int i = 1; i < row; i++) { //process except the first row and column
        for (int j = 1; j < col; j++) 
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;
    }
    if (isZeroCol) { //handle the first column
        for (int i = 0; i < row; i++) 
            matrix[i][0] = 0;
    }
    if (isZeroRow) { //handle the first row
        for (int i = 0; i < col; i++) 
            matrix[0][i] = 0;
    }
}