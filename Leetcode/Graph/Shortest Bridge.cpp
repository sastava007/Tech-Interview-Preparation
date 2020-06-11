/*  FInd the length of shortest bridge, between 2 set of islands 
    1. We first paint one of the islands using DFS with color 2, so we can easily identify island #1 and island #2.
    2. Then we start expanding island #2 by paining connected empty area. Each round, we increase the color (3, 4, and so on) so we can keep track of the newly painted area. This ends when we "bump" into the first island.

    TC: O(mn) time and O(mn) space due to recursive stack
 */

class Solution {
    
private:
    int paint(vector<vector<int>>& A, int i, int j)
    {
        if (i < 0 || j < 0 || i == A.size() || j == A[i].size() || A[i][j] != 1)    //if we're going out of boundary, or this is water cell
            return 0;
        
        A[i][j]=2;      //paint the current cell with #2, and recursively(DFS) call for it neighbouring land calls 
        return (1+paint(A, i-1, j)+paint(A, i+1, j)+paint(A, i, j-1)+paint(A, i, j+1));        
    }
    
    bool expand(vector<vector<int>>& A, int i, int j, int c)
    {
        if (i < 0 || j < 0 || i == A.size() || j == A[i].size()) 
            return false;
        if(A[i][j]==0)
            A[i][j]=c+1;
        
        return (A[i][j]==1);      // check if we've reached the other end of side
        
    }
    
public:
    int shortestBridge(vector<vector<int>>& A) 
    {
        for (int i = 0, found = 0; !found && i < A.size(); ++i)
            for (int j = 0; !found && j < A[0].size(); ++j) 
                found = paint(A, i, j);     // return the no. of cells/ islands which are painted with #2

        for (int c = 2; ; ++c)
        {
            for (int i = 0; i < A.size(); ++i)
            {
                for (int j = 0; j < A.size(); ++j) 
                {
                    if (A[i][j] == c && ((expand(A, i - 1, j, c) || expand(A, i, j - 1, c) || expand(A, i + 1, j, c) || expand(A, i, j + 1, c))))
                            return c - 2;
                }
            }
        }
            
    }
};