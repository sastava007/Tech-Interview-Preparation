/*
    We've to find the minimum feasable water level, such that we can swim from (0,0) node to (n-1,n-1). And at time 't' the depth water level is t, and we only reach cells which has
    water level <= t. And as water level can be at max (N*N-1) ques desc then we can select any discrete value of water level, and if it's possible to reach the target cell with this water level
    then we can also reach for greater value of T, so try to reduce it,

    TC: O(logN*N^2) and Space: O(N^2) We're using DFS to check that whether it's possible to reach the end with this water level or not, and dfs has O(V+E) complexity and a grid has
    N^2 nodes and 4N^2 edges.
*/

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int low = grid[0][0], high = n*n-1;
        while(low<high)
        {
            int mid = low + (high-low)/2;
            if(isValid(grid, mid))
                high = mid;
            else
                low = mid+1;
        }
        return low;
    }
private:  
    vector<pair<int,int>> dirs = {{-1,0}, {0,1}, {1,0}, {0,-1}};
    
    bool isValid(vector<vector<int>>& grid, int waterLevel)
    {
        int n = grid.size();
        vector<vector<int>> visited(n, vector<int>(n,0));
        return dfs(grid, visited, waterLevel, 0, 0);
    }

    bool dfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int waterLevel, int x, int y)
    {
        visited[x][y] = 1;
        int n = grid.size();
        for(auto dir: dirs)
        {
            int r = x+dir.first, c = y+dir.second;
            if(r>=0 && c>=0 && r<n && c<n && !visited[r][c] && grid[r][c]<=waterLevel)
            {
                if(r==n-1 && c==n-1)
                    return true;
                if(dfs(grid, visited, waterLevel, r, c))
                    return true;
            }
        }
        return false;
    }
};

/*  Using Priority Queue: Starting from `(0, 0)` we keep on selecting the neighbor with lower elevation until we reach the end. And to select the neighbours with minimum water level we've to use
    priority queue.

    There are four possible neighbors `(i+1, j), (i-1, j), (i, j+1), (i, j-1)`.
    Every time we select neighbor we check if we visited and choose the smallest elevation to go.

    As there could be atmax N^2 elements in priority_queue and every heap operation is logN, so TC O(N^2 logN)

*/

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size(), ans = max(grid[0][0], grid[n-1][n-1]);
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<vector<int>> visited(n, vector<int>(n, 0));
        visited[0][0] = 1;
        vector<int> dir({-1, 0, 1, 0, -1});
        pq.push({ans, 0, 0});
        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            ans = max(ans, cur[0]);
            for (int i = 0; i < 4; ++i) {
                int r = cur[1] + dir[i], c = cur[2] + dir[i+1];
                if (r >= 0 && r < n && c >= 0 && c < n && visited[r][c] == 0) {
                    if (r == n-1 && c == n-1) return ans;
                    pq.push({grid[r][c], r, c});
                    visited[r][c] = 1;
                }
            }
        }
        return -1;
    }
};