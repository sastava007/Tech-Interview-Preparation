/* 
    Find the distance of nearest 0 for all 1.
    Using BFS: First enqueue all the cells with 0 and then explore the adjacent cells to it and also when we go from one level to another increment the distance.
    
    Given that, there are at least one 0 in the given matrix. So that we can be assured that we'll be able to calculate the nearest distance from 0.
*/

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) 
    {
        vector<vector<int>> res = matrix;
        if(matrix.size()==0 || matrix[0].size()==0)
            return res;
        
        queue<pair<int, int>> q;
        
        for(int i=0; i<matrix.size(); i++)
            for(int j=0; j<matrix[0].size(); j++)
            {
                if(matrix[i][j] == 0)
                    q.push({i, j});
            }
        
        int offset[5] = {-1, 0, 1, 0, -1}, dist = 0;
        while(!q.empty())
        {
            int size = q.size();
            dist++;
            while(size--)
            {
                auto it = q.front();
                q.pop();

                for(int i=0; i<4; i++)
                {
                    int x = it.first + offset[i], y = it.second + offset[i+1];
                    if(x>=0 && x<matrix.size() && y>=0 && y<matrix[0].size() && matrix[x][y]==1)
                    {
                        res[x][y] = dist;
                        matrix[x][y] = 0;
                        q.push({x,y});
                    }
                }
            }
        }
        return res;
    }
};
