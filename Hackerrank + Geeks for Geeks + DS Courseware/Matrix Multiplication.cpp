#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define deb(x) cout<<#x<<" "<<x<<"\n";
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n,i,j,x;
    cin>>n;
    int a[n][n];
    int b[n][n];
    int ans[n][n]={0};

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        cin>>a[i][j];

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        cin>>b[i][j];


    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    for(x=0;x<n;x++)
        ans[i][j]=(ans[i][j]+ (a[i][x]*b[x][j]));

    cout<<"Multiplied matrix is \n";

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        cout<<ans[i][j]<<" ";
        cout<<"\n";
    }

}

