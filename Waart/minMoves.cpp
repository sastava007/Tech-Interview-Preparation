#include<bits/stdc++.h>
using namespace std;

int minMoves()
{
    int n,m;
    cin>>n>>m;

    vector<vector<int>> v(n, vector<int>(m));
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
        {
            cin>>v[i][j];
        }

    for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            cout<<v[i][j]<<" ";

            cout<<"\n";
        }

    queue<pair<int,int>> q;
    q.push({0,0});
    int d = 0;
    while (!q.empty())
    {
        int size = q.size();
        while (size--)
        {
            auto temp = q.front();
            q.pop();
            
            if(temp.first==n-1 && temp.second==m-1)
                return d;
            
            int x1 = temp.first+v[temp.first][temp.second], y1 = temp.second;
            int x2 = temp.first, y2 = temp.second+v[temp.first][temp.second];

            if(x1>=0 && x1<=n-1 && y1>=0 && y1<=m-1)
            {
                q.push({x1,y1});
            }
            if(x2>=0 && x2<=n-1 && y2>=0 && y2<=m-1)
            {
                q.push({x2,y2});
            }
        }
        d++;
    }
    
    return -1;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cout<<minMoves()<<"\n";
    }
    return 0;
}