/*
*   Solved Simple Variation: https://www.geeksforgeeks.org/rat-in-a-maze-backtracking-2/
*   To print all such paths just replace #36 base case to false. as we did in N queen problem to find all possible configuration
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c=0;
bool isSafe(char maze[][1000], int i , int j, int n)
{
    // rat should be always inside the maze
    if(i>n || j>n)
        return false;
    // that path is not blocked
    if(maze[i][j]=='1')
        return false;

    //else
    return true;
}

bool compute(char maze[][1000], int solu[][1000],int i, int j, int n)
{
    // base case
    if(i==n && j==n)
    {
        solu[i][j]=1;
        c++;
        // return false: to print all possible paths
        return false;
    }
    if(isSafe(maze,i,j,n))
    {
        solu[i][j]=1;
        bool forwardMovePossible=compute(maze,solu,i,j+1,n);
        if(forwardMovePossible )
            return true;
        bool downMovePossible=compute(maze,solu,i+1,j,n);

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
    char maze[1000][1000];

    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    cin>>maze[i][j];

    int solu[1000][1000]={0};
    compute(maze,solu,0,0,n-1);
    cout<<c;
}

