/*  
    Given an ininite size grid, find minimum steps required to move the kinght to destination 
    TC & Space: O(maxN*maxN)
    PS: More optimized solution is by using Bidirectional BFS, becz as the grid size is large i.e infinite.
    
    Simple BFS will traverse 1 + B + B^2 + ... + B^k vertices.
    Bi-directional BFS will traverse 2 + 2B^2 + ... + 2B^(k/2) vertices where B = branching factor (each vertex has avg B edges)
*/

int minKnightMoves(int x, int y)
{
    int maxN = 310;
    vector<vector<bool>> visited(maxN, vector<bool>(maxN, false));

    x = abs(x);
    y = abs(y);

    queue<pair<int, int>> q;
    q.push({0,0});      // if asked from other point, then push it here
    visited[0][0]=true;

    int steps=0;
    int x_offset[]={2, 2, -2, -2, 1, 1, -1, -1};
    int y_offset[]={-1, 1, 1, -1, 2, -2, 2, -2};

    while(!q.empty())
    {
        int size = q.size();
        for(int i=0; i<size; i++)
        {
            auto it = q.top();
            q.pop();

            if(it.first==x && it.second==y)
                return steps;
            for(int j=0; j<8; j++)
            {
                int x1= it.first + x_offset[j];
                int y1= it.second + y_offset[j];
                
                if(x1<0 || x1>=maxN || y1<0 || y1>=maxN)
                    continue;

                if(!visited[x1][y1]) {
                    visited[x1][y1] = true;
                    q.push({x1,y1});
                }
            }
        }
        steps++;
    }
    return -1;
}


/*  Idea is to use a BFS for finding the shortest distance b/w source and destination.
    We try all 8 possible position where a Knight can reach from its position. If reachable position is not already visited and is inside the board, we push this state into queue with distance 1 more than its parent state. Finally we return distance of target position, when it gets pop out from queue.

    TC: O(N^2)  In worst case BFS visits all cells on board 
    Space: O(N^2) to maintain visited
 */

// PS: Only works for finite size board 8X8
const int n=8;
struct node
{
    int x, y, dist;
    node(int x_, int y_, int dist_=0)
    {
        x=x_;
        y=y_;
        dist=dist_;
    }
}

bool isValid(int x, int y)
{
    if(x<0 || x>=n || y<0 || y>=n)
        return false;
    return true;
}

int bfs(node src, node dest)
{
    queue<node> q;
    unordered_set<node> visited;

    int row[]={2,2,-2,-2,1,1,-1,-1};
    int col[]={-1, 1, 1, -1, 2, -2, 2, -2};

    q.push({src.x, src.y});
    while(!q.empty())
    {
        node curr = q.front();
        q.pop();

        int x = curr.x;
        int y = curr.y;

        if(x==dest.x && y==dest.y)
            return curr.dist;

        if(visited.find(curr) == visited.end())
        {
            visited.insert(curr);
            for(int i=0; i<8; i++)
            {
                int x1=x+row[i];
                int y1=y+col[i];

                if(isValid(x1, y1))
                    q.push({x1, y1, node.dist+1});
            }
        }
    }

    return INT_MAX;
}

int main()
{
    node src = {0, 7}, dest={7,0};
    cout<<bfs(src, dest);
    return 0;
}