/* 
    Find the minimum steps needed to cut all the trees in increasing order of height, return -1 if not possible.

    Since we always cut off the tree with lowest height first, we collect all trees and sort them by heights.
    If we make sure we walk the minimum steps to cut off each tree, the sum of these minimum steps will be the final answer.
    For cutting each tree (aimX, aimY), we implement BFS once

    TC: O(MN * MN) and Space: O(MN)
*/

class Solution {
public:
    int cutOffTree(vector<vector<int>>& forest) 
    {
        vector<vector<int>> trees;
        for(int i=0; i<forest.size(); i++)
            for(int j=0; j<forest[0].size(); j++)
            if(forest[i][j]>1)
                trees.push_back({forest[i][j], i, j});
        
        sort(trees.begin(), trees.end());
        
        int srcX = 0, srcY = 0, ans = 0;
        
        for(int i=0; i<trees.size(); i++)
        {
            int trgX = trees[i][1], trgY = trees[i][2];
            int steps = bfs(srcX, srcY, trgX, trgY, forest);
            if(steps == -1)
                return -1;
            
            ans += steps;
            srcX = trgX;
            srcY = trgY;
        }
        return ans;
    }

    int bfs(int sr, int sc, int er, int ec, vector<vector<int>>& forest) 
    {
        queue<pair<int, int>> q;
        vector<vector<int>> visited(forest.size(), vector<int>(forest[0].size(), 0));
        
        q.push({sr, sc}); 
        visited[sr][sc] = 1;
        int step = 0;
        
        vector<int> dir = {-1, 0, 1, 0, -1};
        while (!q.empty()) 
        {
            int sz = q.size();
            while(sz--)
            {   
                auto temp = q.front();  
                q.pop();
             
                if(temp.first == er && temp.second == ec)
                    return step;
                
                for (int i = 0; i < 4; i++) 
                {
                    int r = temp.first + dir[i], c = temp.second + dir[i+1];
                    
                    if(r>=0 && r<forest.size() && c>=0 && c<forest[0].size() && !visited[r][c] && forest[r][c]>0)
                    {
                        visited[r][c] = 1;
                        q.push({r, c});
                    }
                }   
            }
            step++;
        }
        return -1;
    }
};