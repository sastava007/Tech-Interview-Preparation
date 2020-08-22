/* 
    GIven a grid to whose (top & left) are Pacific ocean and (right & bottom) are Atlantic ocean. FInd the coordinates from which water can flow to both the ocean, note that what will
    only flow in 4 directions and in those cells whose water level <= current level.

    This problem is similar to 'Longest increasing path in a matrix', so here basically we need to find the decreasing path from inner cell to ocean or increasing path from ocean to
    inner cell.
    We can run dfs() from border i.e ocean and keep on marking places where this water can reach becz its similar to either water goes from center to ocean or come from ocean to center
    So the place which receives water from both the ocean is the desired answer.

    TC & Space: O(N*M)
*/

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) 
    {
        vector<vector<int>> ans;
        if(matrix.size() == 0 || matrix[0].size()==0)
            return ans;
        
        int n = matrix.size(), m = matrix[0].size();
        
        vector<vector<bool>> pacific(n, vector<bool>(m, false)), atlantic(n, vector<bool>(m, false));
        
        for(int i=0; i<n; i++)   // traversing along the boarder is inspired from 'Surrounded Region' problem
        {  
            dfs(matrix, i, 0, pacific);
            dfs(matrix, i, m-1, atlantic);
        }
        for(int i=0; i<m; i++)
        {
            dfs(matrix, 0, i, pacific);
            dfs(matrix, n-1, i, atlantic);
        }
        
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                if(pacific[i][j] && atlantic[i][j])
                    ans.push_back(vector<int>({i,j}));
        
        return ans;
    }
private:
    void dfs(vector<vector<int>>& matrix, int x, int y, vector<vector<bool>>& visited)
    {
        visited[x][y] = true;
        int offset[] = {-1, 0, 1, 0, -1};
        for(int i=0; i<4; i++)
        {
            int x1 = x+offset[i], y1 = y+offset[i+1];
            if(x1<0 || x1>=matrix.size() || y1<0 || y1>=matrix[0].size() || visited[x1][y1] || matrix[x1][y1] < matrix[x][y]) // Water will flow in the increasing path from ocean to inner cell
                continue;
            dfs(matrix, x1, y1, visited);
        }
    }
};