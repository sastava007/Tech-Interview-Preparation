#include<bits/stdc++.h>
#define ll long long
using namespace std;

main()
{
    int m1,n1,m2,n2,i,j,x;
    cin>>m1>>n1>>m2>>n2;
    if(n1==m2)
    {
        int a[m1][n1];
        int b[m2][n2];
        ll ans[m1][n2]={0};

        for(i=0;i<m1;i++)
            for(j=0;j<n1;j++)
            cin>>a[i][j];

        for(i=0;i<m2;i++)
            for(j=0;j<n2;j++)
            cin>>b[i][j];


        for(i=0;i<m1;i++)
        for(j=0;j<n2;j++)
        {
            ll sum=0;
            for(x=0;x<n1;x++)
            sum+= (a[i][x]*b[x][j]);
            ans[i][j]=sum;
        }

        cout<<"Multiplied matrix is \n";

        for(i=0;i<m1;i++)
        {
            for(j=0;j<n2;j++)
            cout<<ans[i][j]<<" ";
            cout<<"\n";
        }
    }


}

