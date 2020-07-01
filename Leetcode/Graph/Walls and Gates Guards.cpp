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

public void wallsAndGates(int[][] rooms) {
    if(rooms==null || rooms.length==0||rooms[0].length==0)
        return;
 
    int m = rooms.length;
    int n = rooms[0].length;
 
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(rooms[i][j]==0){
                fill(rooms, i, j, 0);
            }
        }
    }
}
 
public void fill(int[][] rooms, int i, int j, int distance){
    int m=rooms.length;
    int n=rooms[0].length;
 
    if(i<0||i>=m||j<0||j>=n||rooms[i][j]<distance){
        return;
    }
 
    rooms[i][j] = distance;
 
    fill(rooms, i-1, j, distance+1);
    fill(rooms, i, j+1, distance+1);
    fill(rooms, i+1, j, distance+1);
    fill(rooms, i, j-1, distance+1);
}