/* 
    Flood Fill Algorithm: Base for all DFS problems
    
    TC & Space: O(M*N)
*/

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) 
    {
        vector<vector<int>> res = image;
        
        if(res[sr][sc]==newColor)   // if newColor is already the original color, then there's no reason to update the same and continue that further
            return res;
        
        dfs(res, sr, sc, res[sr][sc], newColor);
        return res;
    }
    
    void dfs(vector<vector<int>>& res, int sr, int sc, int oldColor, int newColor)
    {
        if(sr<0 || sr>=res.size() || sc<0 || sc>=res[0].size() || res[sr][sc] != oldColor)
            return;
        
        res[sr][sc] = newColor;
        dfs(res, sr-1, sc, oldColor, newColor);
        dfs(res, sr, sc+1, oldColor, newColor);
        dfs(res, sr+1, sc, oldColor, newColor);
        dfs(res, sr, sc-1, oldColor, newColor);
    }
};