#include<bits/stdc++.h>
using namespace std;
main()
{
    int n,i;
    cin>>n;
    int a[n],q,r,max=0;
    map<int,int> f;
    bool visited[10];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        q=a[i];
        memset(visited,false,10);
        while(q>0)
        {
            r=q%10;
            if(visited[r]==false&&r!=0)
            {
                f[r]++;
                visited[r]=true;
                if(f[r]>max)
                max=f[r];
            }
            q/=10;
        }
    }
    cout<<max;
}
