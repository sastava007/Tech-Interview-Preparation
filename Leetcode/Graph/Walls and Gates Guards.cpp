/*  We've to find the shortest distance of Gate from open area without going through any wall. 
    The idea is to run a BFS. We first enqueue all the cells that contains a Gate and then we'll explore all it's adjacent 4 cells, if they are valid and their current distance 
    is greater then we'll update them with correct distance i.e dist[i][j]+1. We are interested in knowing how far away is any cell from the gate.
*/

#include<bits/stdc++.h>
using namespace std;

bool isValid(int a[100][100], int n, int m, int x, int y)
{
    return (x>=0 && x<=n && y>=0 && y<=m && a[x][y]!=-1);
}


void findDistance(int a[100][100], int n, int m)
{
    int dist[n][m];
    queue<pair<int,int>> q;

    int X[4]={-1, 0, 1, 0};
    int Y[4]={0, 1, 0, -1};

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(a[i][j] == 0)    //if guard: then push it into queue
            {
                q.push({i,j});
                dist[i][j]=0;
            }
            else if(a[i][j]==-1)    //if wall/or some other hindrance
                dist[i][j]=-1;
            else
                dist[i][j]=INT_MAX;
        }
    }

    while(!q.empty())
    {
        int x = q.front().first, y = q.front().second;
        q.pop();
        for(int i =0; i<4; i++)
        {
            int x1 = x+X[i];
            int y1 = y+Y[i];

            if(isValid(a, n, m, x1, y1) && dist[x1][y1] > dist[x][y]+1)
            {
                dist[x1][y1]=dist[x][y]+1;
                q.push({x1, y1});
            }
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
            cout<<dist[i][j]<<" ";
        
        cout<<"\n";
    }
        
}

int main()
{

    int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		int arr[100][100];
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
			{
				char ch;
				cin>>ch;
				if(ch=='G') // If Guard/Gate
				arr[i][j]=0;
				else if(ch=='W')    // If Wall or some other hindrance
				arr[i][j]=-1;
				else if(ch=='O')    // If Open Area
				arr[i][j]=1;
			}
			findDistance(arr,n,m);
	}  

}