/*  Similar to problem finding battletanks, i.e check from top and left 
    In this problem there exist just 1 island, and we've to find it's perimeter
*/

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

/*  Find the Maximum perimeter of any island. Here perimeter is defined in a different i.e the "number of land(1) cells that is adjacent to a 0 OR grid boundary to the left, right, up, or down" 
    TC: O(R*C) and here we're modifying the grid itself, but we can maintain a seen[][] that requires additional O(r*c) space and also the space required for recursion call stack.

    The condition is to not count the 1 in the middle if it's surrounded by other 1's in up, down, left and right.


*/

class Solution
{
    public: 
        int largestPerimeterIsland(vector<vector<int>>& grid)
        {
            int res = 0;
            for(int r = 0; r < grid.size(); ++r)
                for(int c = 0; c < grid[0].size(); ++c)
                    if(grid[r][c] == 1)
                        res = max(res, perimeter(grid, r, c));
            return res;
        }
 
     protected:
        int perimeter(vector<vector<int>>& grid, int r, int c)
        {
            vector<pair<int, int>> next = {{r+1, c}, {r-1, c}, {r, c+1}, {r, c-1}};
            bool is_perimeter = false;
            int result = 0;
            grid[r][c] = 2; // 'visited';
            for(auto& [row, col] : next)
            {
                if(is_water(grid, row, col))
                    is_perimeter = true;
                else if(grid[row][col] == 1)
                    result += perimeter(grid, row, col);
            }
            return is_perimeter ? result + 1 : result;
        }
 
        bool is_water(vector<vector<int>>& grid, int r, int c)
        {
            return (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] == 0);
        }
};
 
int main() 
{
 
	Solution obj;
	vector<vector<int>> v{{1, 0, 1, 1, 1}, {1, 0, 1, 1, 1}, {0, 1, 0, 1, 1}};
	cout<<obj.largestPerimeterIsland(v);
 
	return 0;
}