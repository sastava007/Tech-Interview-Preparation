#include<bits/stdc++.h>
#define ll long long int
using namespace std;

set<vector<ll>> ans;
void dfs(vector<int> G[], bool vis[], int s, int m, ll *a)
{
    int c=0;
    vis[s]=true;
    for(auto it:G[s])
        if(!vis[it])
        {
            c++;
            if(c<=m)
            {
                vector<ll> v(3);
                v[0]=s;
                v[1]=it;
                v[2]=a[c-1];
                ans.insert(v);
            }
            dfs(G,vis,it,m,a);
        }
}

main()
{
    int n,m,i;
    cin>>n>>m;
    vector<int> G[n+1];
    bool vis[n+1];

    for(int i=1;i<=n;i++)
    vis[i]=false;

    ll a[m];
    for(i=0;i<m;i++)
    cin>>a[i];

    int e[n-1];
    for(i=0;i<n-1;i++)
        cin>>e[i];

    for(i=0;i<n-1;i++)
    {
        G[e[i]].push_back(e[i]+1);
        G[e[i]+1].push_back(e[i]);
    }
    //dfs(G,vis,1,m,a);

    //cout<<ans.size()<<"\n";
    for(auto it:G)
    {
        for(auto jt:it)
        cout<<jt<<" ";
        cout<<"\n";
    }
}
