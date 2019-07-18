#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool isSafe(int mat[][9],int i,int j, int n, int num)
{
    //check if that element is already present in row or column
    for(int x=0;x<n;x++)
        if((mat[i][x]==num) || (mat[x][j]==num))
        return false;

    //check in sub-grid
    int sr=sqrt(n);
    int Sx=(i/sr)*sr;
    int Sy=(j/sr)*sr;
    for(int x=Sx;x<(Sx+sr);x++)
        for(int y=Sy;y<(Sy+sr);y++)
        if(mat[x][y]==num)
        return false;

    // else
    return true;
}

bool sudokuSolver(int mat[][9],int i,int j, int n)
{
    //base case
    if(i==n)
    {
        for(int x=0;x<n;x++)
        {
            for(int y=0;y<n;y++)
                cout<<mat[x][y]<<" ";
            cout<<"\n";
        }
        return true;
    }

    // corner cases check: If we are at last column
    if(j==n)
    return sudokuSolver(mat,i+1,0,n);
    // if cell is already not empty
    if(mat[i][j]!=0)
        return sudokuSolver(mat,i,j+1,n);
    // Recursive case
    for(int num=1;num<=n;num++)
    {
        // assume that later matrix can be solved using recursion
        if(isSafe(mat,i,j,n,num))
        {
            mat[i][j]=num;
            bool nextPossible=sudokuSolver(mat,i,j+1,n);
            if(nextPossible)
                return true;
        }
    }
    // if no such solution exist after trying all numbers from 1-9, which means that our assumption was wrong so we need to backtrack this move
    mat[i][j]=0;
    return false;

}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int mat[9][9]={   {3, 0, 6, 5, 0, 8, 4, 0, 0},
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};

    sudokuSolver(mat,0,0,9);
}

