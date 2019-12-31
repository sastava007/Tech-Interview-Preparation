#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define deb(x) cout<<#x<<" "<<x<"\n"

int ans=INT_MAX;
int c=0;
void dfs(vector<int> G[], bool vis[], int s)
{
    c++;
    vis[s]=true;
    for(auto it:G[s])
    if(!vis[it])
    dfs(G,vis,it);
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;
    vector<int> G[n+1];
       bool vis[n+1];
       for(int i=1;i<=n;i++)
        vis[i]=false;
    int gf=INT_MAX;
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    int q;
    cin>>q;
    while(q--)
    {
       int x;
       cin>>x;
       dfs(G,vis,x);
       if(c<=ans)
         {
             ans=c;
             gf=min(gf,x);
         }
        c=0;
    }
    cout<<gf;
}
