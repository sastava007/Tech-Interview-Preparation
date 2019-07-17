#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool isSafe(int i, int j, int n, int board[][10])
{
    //check in current column -- upward side
    for(int row=i;row>=0;row--)
        if(board[row][j]==1)
        return false;

    // check for right diagonal
    int x=i,y=j;
    while(x>=0 && y<n)
    {
        if(board[x][y]==1)
        return false;

        x--;
        y++;
    }

    // check for left diagonal
    x=i,y=j;
    while(x>=0 && y>=0)
    {
        if(board[x][y]==1)
        return false;

        x--;
        y--;
    }
    // If we reached till here, now it means position is safe
    return true;
}


bool compute(int board[][10],int i, int n)
{
    if(i==n)
        {
            // print configuration of board
            for(int x=0;x<n;x++)
            {
                for(int y=0;y<n;y++)
                {
                    if(board[x][y])
                    cout<<" Q ";
                    else
                    cout<<" __ ";
                }
                cout<<"\n";
            }
            cout<<"\n";
            // to print just all such configuration of board
            return false;
        }
        // Recursive case:
        // try to place the queen in current row and call on the remaining part assuming that recursion will solve it
        for(int j=0;j<n;j++)
        {
            if(isSafe(i,j,n,board))
            {
                //Placing the queen at (i,j) assuming it correct
                board[i][j]=1;
                bool nextQueenSafe=compute(board,i+1,n);
                if(nextQueenSafe)
                    return true;

                // if current position is not correct then backtrack / undo that move
                 board[i][j]=0;
            }
        }
        return false;
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    int board[10][10]={0};
    compute(board,0,n);
}

