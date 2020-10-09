bool isPrime(int n)
{
    if(n==1)
        return false;
        
    int flag = 0;
    for (i = 2; i <= n / 2; ++i) 
    {
        if (n % i == 0) {
            flag = 1;
            break;
        }
    }
    return (flag == 0) ?false:true;
}

int shortestPathBinaryMatrix(string s) 
{
    vector<vector<int>> grid(10, vector<int>(10));

    int n = s[0], m = s[1];

    if(grid.size()==0 || grid[0].size()==0)
        return 0;
    if(grid[0][0]==1)
        return -1;
    
    int dist = 0;
    queue<pair<int, int>> q;
    q.push({n,m});
    
    
    while(!q.empty())
    {
        int size = q.size();
        dist++;
        while(size--)
        {
            auto temp = q.front();
            q.pop();
            
            if(temp.first == 10 || temp.first == -1 || temp.second == 10 || temp.second == -1)
                return dist;
            
            int sum = temp.first + temp.second;
            bool prime = isPrime(sum), comp  = isComposite(sum), squareCube = isSquareCube(sum);
            

            vector<pair<int, int>> dirs;

            if(prime)
                dirs.push_back(vector<int>({temp.first+1, temp.second}));
            if(compoite)


            for(auto it: dirs)
            {
                int x = temp.first + it.first, y = temp.second + it.second;
                if(x>=0 && x<grid.size() && y>=0 && y<grid[0].size() && grid[x][y]==0)
                {
                    q.push({x,y});
                    grid[x][y] = 1;   // Mark visited to otherwise if may be possible that same node is getting enqueued every time
                }
            }
        }
    }
    return -1;
}