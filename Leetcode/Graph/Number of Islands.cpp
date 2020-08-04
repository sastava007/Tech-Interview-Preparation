/*  The idea is to recursively tarverse the grid using a DFS, and increase the counter when we encounter a grid[][]='1', and we basically reset 
    it so that we don't call its again & again. Basically we have to count the no. of connected components

    TC: O(M*N) and Space: O(M*N) worst case space complexity when grid is all full of land(1) then recursion will go m*n levels deep
    
    visited[][] can also be used, instead of directly modifying the grid, OR we can update the visited island to 2 and later do %=2 this way we don't need extra space
*/

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) 
    {
        int n = grid.size();
        if(n==0)
            return 0;

        int m = grid[0].size();
        
        int islands = 0;
        
        for(int i=0;i<n;i++)
            for(int j=0; j<m; j++)
            {
                if(grid[i][j] == '1')
                {
                    islands++;
                    dfs(grid, i, j, n, m);
                }
            }
        return islands;
    }
    
    private:
    void dfs(vector<vector<char>>& grid, int x, int y, int n, int m)
    {
        if(x<0 || y<0 || x>=n || y>=m || grid[x][y]=='0')
            return;
        
        grid[x][y]='0';     //  Rather than changing it to 0. You can change it to 2 and then do a %2 at the end for all matrix elements. (NO EXTRA SPACE)
        
        dfs(grid, x-1, y, n, m);
        dfs(grid, x, y+1, n, m);
        dfs(grid, x+1, y, n, m);
        dfs(grid, x, y-1, n, m); 
    }
};

/*  Iterative BFS, similar intution & concept 
    TC: O(M*N) and Space: O(N)

*/
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = m ? grid[0].size() : 0, islands = 0, offsets[] = {0, 1, 0, -1, 0};
        for (int i = 0; i < m; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                if (grid[i][j] == '1') 
                {
                    islands++;
                    grid[i][j] = '0';

                    queue<pair<int, int>> todo;
                    todo.push({i, j});
                    while (!todo.empty()) 
                    {
                        pair<int, int> p = todo.front();
                        todo.pop();
                        for (int k = 0; k < 4; k++) 
                        {
                            int r = p.first + offsets[k], c = p.second + offsets[k + 1];
                            if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == '1') 
                            {
                                grid[r][c] = '0';
                                todo.push({r, c});
                            }
                        }
                    }
                }
            }
        }
        return islands;
    }
};

/* 
    Follow Up: If the matrix is super large and sparse means most of positions are 0 just keep the positions of the ones as a set of tuples. The DFS algorithm will work the same, 
    instead querying the matrix for the next position you query the set of tuples, if the position exist you continue the traversal. 
    We can use a hash_map<pair<int x, int y>>
    
*/