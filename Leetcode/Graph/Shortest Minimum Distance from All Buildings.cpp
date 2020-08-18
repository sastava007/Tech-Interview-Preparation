/* 
    We've to setup a new building on an empty land, such that the distance from this new building to all other buildings should remain shortest.
    
    Idea is to traverse the matrix, and for every building use BFS to compute the shortest distance from every land(0) to this building. And after we done doing the same for all buildings
    we'll be having a dist matrix of shortest distance from land(0) to all the reachable buildings.

    We'll also maintain the no. of buildings each land(0) can reach, and if this no. is equal to the total no. of buildings then we update our shortest distance

    The shortest distance from an empty land to a bulding can be calculate in O(MN) time by starting the BFS from building, therefore
    we can calculate the distance from all buildings to empty land in by running BFS from every building, so total TC = (#building * MN) => O(M^2 N^2)
    
*/

int shortestDistance(vector<vector<int>> &grid)
{
    if(grid.size()==0 || grid[0].size()==0)
        return -1;

    int n = grid.size(), m = grid[0].size();

    vector<vector<int>> dist(n, vector<int> (n,0)), reach(n, vector<int> (n,0));    // We've to make sure that empty land should be reachable from all buildings, so maintain a reach[][]

    int buildings = 0;

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
        {
            if(grid[i][j] == 1)
            {
                buildings++;
                bfs(grid, dist, reach, i, j);
            }
        }

    int minDistance = INT_MAX;

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
        {
            if(reach[i][j] == buildings)      // if the no. of building that we can reach from this land is equal to the total no. of buildings in grid, then update the minimum distance 
                minDistance = min(minDistance, dist[i][j]);
        }
    
    return minDistance == INT_MAX?-1:minDistance;
}

void bfs(vector<vector<int>> &grid, vector<vector<int>> &dist, vector<vector<int>> &reach, int x, int y)
{
    int n = grid.size(), m = grid[0].size();
    queue<pair<int,int>> q;

    vector<vector<bool>> visited(n, vector<bool> (n,false));
    q.push({x,y};
    visited[x][y] = true;

    int dist = 0;

    while(!q.empty())
    {
        int size = 0;
        dist++;
        while(size--)
        {
            auto temp = q.front();
            q.pop();
            for(int i=0; i<4; i++)
            {
                int x1 = x+row[i], y1 = y+col[i];
                if(x1>=0 && y1>=0 && x1<n && y1<m && grid[x1][y1]==0 && !visited[x1][y1])
                {
                    q.push({x1,y1});
                    visited[x][y1] = true;

                    reach[x1][y1]++;
                    dist[x1][y1] += dist;
                }
            }
        }
    }
}