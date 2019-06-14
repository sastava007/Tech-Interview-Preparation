#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,i,j,flag;
    cin>>t;
    while(t--)
    {
        cin>>n;
        flag=0;
        int a[n][n];
        for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        cin>>a[i][j];

        for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(a[i][j]!=a[j][i])
                flag=1;
        if(flag==0)
        cout<<"Possible"<<endl;
        else
            cout<<"Impossible"<<endl;
    }
    return 0;
}
