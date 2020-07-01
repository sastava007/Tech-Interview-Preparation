/*  
    Naive solu is to simply multiply matrices as we do i.e res[i][j] += a[i][k]*b[k][j]
    One thing to observe is that if we when a[i][k]=0, then res[i][j] will also be ultimately zero 0. So what we can do is to first check if A matrix is not zero then only
    perform the multiplication, and we can do this by swapping(switching) the (j,k) loops.

    TC: O(N^2) in case of sparse multiplication


     |  1 0 0 |   | 7 0 0 |   |  7 0 0 |
     | -1 0 3 | x | 0 0 0 | = | -7 0 3 |
                  | 0 0 1 |

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

/* Convert the sparse matrix to a dense matrix, by storing it into a hash-map */
public class Solution {
    public int[][] multiply(int[][] A, int[][] B) {
        if (A == null || A.length == 0 ||
            B == null || B.length == 0) {
            return new int[0][0];    
        }
         
        int m = A.length;
        int n = A[0].length;
        int l = B[0].length;
         
        int[][] C = new int[m][l];
         
        // Step 1: convert the sparse A to dense format
        Map<Integer, Map<Integer, Integer>> denseA = new HashMap<>();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (A[i][j] != 0) {
                    if (!denseA.containsKey(i)) {
                        denseA.put(i, new HashMap<>());
                    }
                    denseA.get(i).put(j, A[i][j]);
                }
            }
        }
         
        // Step 2: convert the sparse B to dense format
        Map<Integer, Map<Integer, Integer>> denseB = new HashMap<>();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < l; j++) {
                if (B[i][j] != 0) {
                    if (!denseB.containsKey(i)) {
                        denseB.put(i, new HashMap<>());
                    }
                    denseB.get(i).put(j, B[i][j]);
                }
            }
        }
         
        // Step3: calculate the denseA * denseB
        for (int i : denseA.keySet()) {
            for (int j : denseA.get(i).keySet()) {
                if (!denseB.containsKey(j)) {
                    continue;
                }
                 
                for (int k : denseB.get(j).keySet()) {
                    C[i][k] += denseA.get(i).get(j) * denseB.get(j).get(k);
                }
            }
        }
         
        return C;
    }
} 
