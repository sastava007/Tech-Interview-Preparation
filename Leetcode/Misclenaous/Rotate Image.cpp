/* 
    Clockwise 
     - First find the transpose of matrix
     - Then reverse each row 
*/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) 
    {
        for(int i=0; i<matrix.size(); i++)
            for(int j=i; j<matrix[i].size(); j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        
        for(int i=0; i<matrix.size(); i++)
            reverse(matrix[i].begin(), matrix[i].end());
        
    }
};

/* Anticlockwise
    - Transpose step remains same
    - Instead of reverse rows, reverse the column
*/