/*  
    Naive solu is to simply multiply matrices as we do i.e res[i][j] += a[i][k]*b[k][j] 
    One thing to observe is that if we when a[i][k]=0, then res[i][j] will also be ultimately zero 0. So what we can do is to first check if A matrix is not zero then only
    perform the multiplication, and we can do this by swapping(switching) the (j,k) loops.

    TC: O(N2) in case of sparse multiplication
*/

class Solution {
public:

    vector<vector<int>> multiply(vector<vector<int>> &A, vector<vector<int>> &B) 
    {
        int row=A.size();
        int col=B[0].size();
        
        vector<vector<int>> result(row, vector<int>(col, 0));
        
        for(int i=0; i<row; i++)
        {
            for(int k=0; k<A[0].size(); k++)
            {
                if(A[i][k]==0)
                    continue;
                for(int j=0; j<col; j++)
                    result[i][j] += A[i][k]*B[k][j];
            }
        }
        
        return result;
    }
};