#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define deb(x) cout<<#x<<" "<<x<"\n"

ll ans=0,temp=0;


void dfs(vector<int> G[], bool vis[], int s, ll *a)
{
    temp+=a[s-1];
    vis[s]=true;
    for(auto it:G[s])
    if(!vis[it])
    dfs(G,vis,it,a);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
       int n,m;
       cin>>n>>m;
       ll a[n];
       vector<int> G[n+1];
       bool vis[n+1];
       for(int i=1;i<=n;i++)
        vis[i]=false;
       for(int i=0;i<m;i++)
       {
           int a,b;
           cin>>a>>b;
           G[a].push_back(b);
           G[b].push_back(a);
       }

       for(int i=0;i<n;i++)
        cin>>a[i];
        for(int i=1;i<=n;i++)
        {
            if(!vis[i])
            {
                dfs(G,vis,i,a);
                ans=max(ans,temp);
                temp=0;
            }
        }
        ans=max(ans,temp);
        cout<<ans<<"\n";
        ans=0;
        temp=0;
    }
    return 0;
}

