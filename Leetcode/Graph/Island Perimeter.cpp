/* Similar to problem finding battletanks, i.e check from top and left */

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) 
    {
        int result=0;
        if(grid.size()==0 || grid[0].size()==0)
            return 0;
        
        for(int i=0; i<grid.size(); i++)
        {
            for(int j=0; j<grid[i].size(); j++)
            {
                if(grid[i][j]==1)
                {
                    result += 4;
                    
                    if(i>0 && grid[i-1][j]==1)
                        result -= 2;
                    if(j>0 && grid[i][j-1]==1)
                        result -= 2;
                }
            }
        }
        return result;
    }
};

