#include<bits/stdc++.h>
using namespace std;

int minMoves()
{
    int n,m;
    cin>>n>>m;

    vector<vector<int>> v(n, vector<int>(m));
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin>>v[i][j];

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

int minMoves2()
{
    int n,m;
    cin>>n>>m;

    vector<vector<int>> v(n, vector<int>(m));
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin>>v[i][j];

    vector<vector<int>>dp(n,vector<int>(m,INT_MAX));
	dp[0][0]=0;
 
	// for(int i=0;i<n;i++){
	//     if(i+v[i][0]<n)
	//        dp[i+v[i][0]][0] = min(dp[ i + v[i][0]][0] , dp[i][0] + 1);
	// }
 
	// for(int i=0;i<m;i++){
	//     if( i + v[0][i] < m)
	//       dp[0][ i + v[0][i] ] = min(dp[0][ i + v[0][i]] , dp[0][i] + 1 ); 
	// }
 
	for(int i=0;i<n;i++)
    {
	    for(int j=0;j<m;j++){
	        if( i + v[i][j] < n)
	           dp[ i + v[i][j] ][j] = min(dp[ i + v[i][j]][j] , dp[i][j] + 1 );
	        if( j + v[i][j] < m)
	           dp[i][ j + v[i][j] ] = min(dp[i][ j + v[i][j] ] , dp[i][j] + 1 );
	    }
	}
 
	if(dp[n-1][m-1] == INT_MAX)
	  return -1;

	return dp[n-1][m-1];
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cout<<minMoves2()<<"\n";
    }
    return 0;
}