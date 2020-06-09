/* Idea is to use a BFS for finding the shortest distance b/w source and destination
    TC: O(N2)
    Space: O(N)
 */

#include<bits/stdc++.h>
using namespace std;


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

    node src = {0, 7};
    node dest = {7, 0};

    cout<<bfs(src, dest);


    return 0;
}