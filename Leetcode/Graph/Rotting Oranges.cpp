/* 
    Find the minimum time in which all the oranges inside the grid will become rotten.
    Here we're using BFS instead of DFS becz we need to process/rotten all the adjancet oranges at the same time i.e all the oranges in same level will get rotted at the same time
    so we can't use DFS which go by depth.
    
    TC & Space: O(M*N)
*/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        int time = 0, freshOranges=0;
        queue<pair<int, int>> q;
        for(int i=0; i<grid.size(); i++)
            for(int j=0; j<grid[0].size(); j++)
            {
                if(grid[i][j] == 2)
                    q.push({i,j});
                else if(grid[i][j] == 1)
                    freshOranges++;
            }
        
        int offset[] = {-1, 0, 1, 0, -1};
        if(freshOranges == 0)
            return 0;
        
        while(!q.empty() && freshOranges>0)       // Added freshOranges>0 check incase if we've already corodded all the oranges but still we've a few rooted oranges left in queue 
        {                                        // So we don't waste time processing the queue.
            int size = q.size();
            time++;
            while(size--)
            {
                auto temp = q.front();
                q.pop();
                for(int i=0; i<4; i++)
                {
                    int x = temp.first + offset[i];
                    int y = temp.second + offset[i+1];
                    if(x>=0 && x<grid.size() && y>=0 && y<grid[0].size() && grid[x][y] == 1)
                    {
                        grid[x][y] = 2;
                        freshOranges--;
                        q.push({x,y});
                    }
                }
            }
        }
        return freshOranges == 0?time:-1;
    }
};