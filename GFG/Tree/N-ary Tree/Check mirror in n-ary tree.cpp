/* 
    1)Make adjacency list of graph1
    2)Make adj list of graph 2
    3)reverse adjancency list of graph 2
    4)compare both the adjancecy list

    Consider both the graph as directed
*/

#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int t, n, e;
    cin>>t;
    while(t--)
    {
        cin>>n>>e;
        int u, v;
        
        vector<int> g1[n], g2[n];
        
        for(int i=0;i<e;i++)    //first graph
        {
            cin>>u>>v;
            g1[u].emplace_back(v);
        }
        
        for(int i=0;i<e;i++)    //second graph
        {
            cin>>u>>v;
            g2[u].emplace_back(v);
        }
        
        for(int i=0;i<n;i++)    //reversing the second graph
            reverse(g2[i].begin(), g2[i].end());
            
        bool flag=true;
        
        for(int i=0;i<n;i++)
            if(g1[i] != g2[i])
            {
                flag=false;
                break;
            }
            
        flag?cout<<"1\n":cout<<"0\n";
    }
	return 0;
}