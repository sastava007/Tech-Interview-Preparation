/* 
    We've to group the region and flip all the Os in that surrounded region to X. A region is said to be surrounded if it doesn't contain a 'O' which is on boundary.

    Approach:
    1. First traverse across the boundary and run DFS() to mark cells having 'O' to a special character. This way we get rid of regions that shares a cell with boundary becz
       those are already marked with a special character.

    2. Traverse the board again and unmark all the special characters to 'O' and remaining 'O' to 'X'.
    
    TC & Space: O(M*N)
*/

class Solution {
public:
    void solve(vector<vector<char>>& board) 
    {
        if(board.size()==0 || board[0].size()==0)
            return;
     
        int n = board.size(), m = board[0].size();
        
        for(int i=0; i<n; i++)      // traverse through the row [0, m-1]th column
        {
            if(board[i][0]=='O')
                dfs(board, i, 0);
            if(board[i][m-1]=='O')
                dfs(board, i, m-1);
        }
        for(int i=0; i<m; i++)      // traverse through the column [0, n-1]th row
        {
            if(board[0][i]=='O')
                dfs(board, 0, i);
            if(board[n-1][i]=='O')
                dfs(board, n-1, i);
        }
        
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
            {
                if(board[i][j]=='*')
                    board[i][j] = 'O';
                else if(board[i][j]=='O')
                    board[i][j] = 'X';
            }
    }
    void dfs(vector<vector<char>> &board, int x, int y)
    {
        if(x<0 || x>=board.size() || y<0 || y>=board[0].size() || board[x][y]!='O')
            return;   
        board[x][y] = '*';
        
        dfs(board, x-1, y);
        dfs(board, x, y+1);
        dfs(board, x+1, y);
        dfs(board, x, y-1);
    }
};