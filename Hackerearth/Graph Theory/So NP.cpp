#include<bits/stdc++.h>
using namespace std;
#define ll long long

void dfs(vector<int> G[], bool vis[], int s)
{
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

    int n,m,k;
    cin>>n>>m>>k;
    vector<int> G[n+1];
    bool vis[n+1];
    for(int i=1;i<=n;i++)
        vis[i]=false;

    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }
    int c=0;
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==false)
            {
                dfs(G,vis,i);
                c++;
            }
    }
    if(c<=k)
        cout<<m-n+k;
    else
        cout<<"-1";

}
