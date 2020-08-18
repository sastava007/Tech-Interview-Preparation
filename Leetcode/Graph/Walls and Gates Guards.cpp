/*  
    So basically we are interested in knowing how far away is any cell from the gate and we've to find the shortest distance of Gate from open area without going through any wall. 
    The idea is to run a BFS. We first enqueue all the cells that contains a Gate and then we'll explore all it's adjacent 4 cells, if they are valid and their current distance 
    is greater then we'll update them with correct distance i.e dist[i][j]+1. 

    TC: O(M*N) and Space: O(M*N)

    Here empty spaces are initially initialized value of INT_MAX, it also may be the case that it's not possible to reach to a gate then in that case dist persists it's maximum value
*/

class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) 
    {
        if (rooms.empty()) return;
        int m = rooms.size(), n = rooms[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) 
            {
                if (rooms[i][j] == 0)   // first enque all the gates/guards whatever we have
                    q.push({i, j});
            }
        
        int dist = 0;
        int X[4]={-1, 0, 1, 0};
        int Y[4]={0, 1, 0, -1};
        
        while(!q.empty())
        {
            dist++;
            int size = q.size();
            while(size--)       // explore all the neighbouring nodes, and once we're done with all neighboring nodes increase the distance as we've to move to next level
            {
                auto it = q.front();
                q.pop();
                for(int i=0; i<4; i++)
                {
                    int xx = it.first+X[i], yy = it.second+Y[i];
                    if(xx>=0 && yy>=0 && xx<m && yy<n && dist < rooms[xx][yy])
                    {
                        q.push({xx, yy});
                        rooms[xx][yy] = dist;
                    }
                }
            }
        }
    }
};

/* DFS:  */

class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) 
    {
        if(rooms.size()==0 || rooms[0].size()==0)
            return;
        
        for(int i=0; i<rooms.size(); i++)
            for(int j=0; j<rooms[0].size(); j++)
            {
                if(rooms[i][j] == 0)
                    dfs(rooms, i, j, 0);
            }
    }
    void dfs(vector<vector<int>>& rooms, int x, int y, int dist)
    {
        if(x<0 || x>=rooms.size() || y<0 || y>=rooms[0].size() || rooms[x][y]<dist)
            return;
        
        rooms[x][y] = dist;
        dfs(rooms, x-1, y, dist+1);
        dfs(rooms, x, y+1, dist+1);
        dfs(rooms, x+1, y, dist+1);
        dfs(rooms, x, y-1, dist+1);
    }
};