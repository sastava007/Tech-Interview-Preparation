#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define deb(x) cout<<#x<<" "<<x<<"\n";

bool isSafe(int i, int j , int n, int m, int a[][1001])
{
    if(i>n || j>m)
        return false;
    if(a[i][j]==0)
        return false;

    return true;
}

int max_pond=0;
bool expandPond(int i, int j, int n, int m, int a[][1001], int c)
{
    //base case
    if(i==n && j==m)
    {
       max_pond=max(c+1, max_pond);

       // to get all possible paths
       return true;
    }

    if(j>m)
        expandPond(i+1,0,n,m,a,c);

    if(isSafe(i,j,n,m,a))
    {
        bool down=expandPond(i+1,j,n,m,a,c+1);
        if(down)
        {

            return true;
        }

        bool left=expandPond(i,j-1,n,m,a,c+1);
        if(left)
        {

            return true;
        }

        bool right=expandPond(i,j+1,n,m,a,c+1);
        if(left)
        {

            return true;
        }

        bool up=expandPond(i-1,j,n,m,a,c+1);
        if(left)
        {

            return true;
        }

        //backtracking
        //c=0;
        return false;
    }
    a[i][j]=1;
    expandPond(i,j+1,n,m,a,c+1);

}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m,n,i,j;
    cin>>n>>m;
    int a[n][1001];
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
        cin>>a[i][j];
    expandPond(0,0,n-1,m-1,a,0);
    cout<<max_pond;

}

