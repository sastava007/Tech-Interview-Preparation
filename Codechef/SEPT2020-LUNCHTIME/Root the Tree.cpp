#include<bits/stdc++.h>
#define ll long long int
using namespace std;
void dfs(vector<int>a[], int n, bool visited[], int &ans, bool root[])
{
	visited[n]=true;
	for(int i=0;i<a[n].size();i++)
	{
		if(!visited[a[n][i]])
		{
			dfs(a,a[n][i],visited,ans,root);
		}
		else
		{
			if(root[ a[n][i] ]==true)
			{
				root[a[n][i]]=false;
			}
			else
			{
				ans++;
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int tc,n,x,y,ans;
	cin>>tc;
	while(tc--)
	{
		ans=0;
		cin>>n;
		vector<int>a[n+1];
		bool visited[n+1];
		bool root[n+1];
		for(int i=1;i<n;i++)
		{
			visited[i]=false;
			cin>>x>>y;
			a[x].push_back(y);
		}
		for(int i=0;i<=n;i++)
		{
			visited[i]=false;
			root[i]=false;
		}
		for(int i=1;i<=n;i++)
		{
			if(visited[i]==false)
			{
				root[i]=true;
				dfs(a,i,visited,ans,root);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}