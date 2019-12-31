
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        set<int> s;
        for(int i=0;i<n;i++)
        {
            int a,b;
            cin>>a>>b;
            s.insert(a);
            s.insert(b);
        }
        cout<<s.size()<<"\n";

    }

    return 0;
}

