/*
*   Solved Simple Variation: https://www.geeksforgeeks.org/rat-in-a-maze-backtracking-2/
*
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool isSafe(char maze[][10], int i , int j, int m, int n)
{
    // rat should be always inside the maze
    if(i>m || j>n)
        return false;
    // that path is not blocked
    if(maze[i][j]=='X')
        return false;

    //else
    return true;
}

bool compute(char maze[][10], int solu[][10],int i, int j, int m, int n)
{
    // base case
    if(i==m && j==n)
    {
        solu[i][j]=1;
        for(int x=0;x<=m;x++)
            {
                for(int y=0;y<=n;y++)
                    cout<<solu[x][y]<<" ";

                cout<<"\n";
            }
            return true;
    }
    if(isSafe(maze,i,j,m,n))
    {
        solu[i][j]=1;
        bool forwardMovePossible=compute(maze,solu,i,j+1,m,n);
        if(forwardMovePossible )
            return true;
        bool downMovePossible=compute(maze,solu,i+1,j,m,n);

        if(downMovePossible)
            return true;
        else
        {
            // when forward and downward both move are blocked then simply backtrack/undo that move
            solu[i][j]=0;
            return false;
        }
    }
    return false;
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    char maze[10][10]={"0000",
                       "00X0",
                       "000X",
                       "0X00"};
    int solu[10][10]={0};
    compute(maze,solu,0,0,3,3);
}
