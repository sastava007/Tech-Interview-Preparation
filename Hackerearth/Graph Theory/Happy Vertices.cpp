
/*      Problem: https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/happy-vertices/
 *      Approach: Used DFS function two times first to find number of child of each vertex and second to count happy Vertices i.e no of such vertices where no of children of child vertex is
 *                 greater than it's parent
 */

#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int> G[], bool vis[], int s, int child[])
{
    int c=0;
    vis[s]=true;
    for(auto it:G[s])
    {
        if(!vis[it])
        {
            c++;
            dfs(G,vis,it,child);
        }
    }
    child[s]=c;

}

int c=0;
int countDFS(vector<int> G[], bool vis[], int s, int child[])
{
    vis[s]=true;
    for(auto it:G[s])
    {
        if(!vis[it])
        {
            if(child[it]>child[s])
            c++;
            countDFS(G,vis,it,child);
        }
    }
    return c;
}

main()
{
    int n,m;
    cin>>n>>m;
    vector<int> G[n+1];
    bool vis[n+1]={false};

    int child[n+1]={0};

    while(m--)
    {
        int a,b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for(int i=1;i<=n;i++)
    if(!vis[i])
    dfs(G,vis,i,child);

    for(int i=1;i<=n;i++)
    vis[i]=false;
    int ans=0;

    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            countDFS(G,vis,i,child);
            ans+=c;
            c=0;
        }
    }
    cout<<ans;

}
