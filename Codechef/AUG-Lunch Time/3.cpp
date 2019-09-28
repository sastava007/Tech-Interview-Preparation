#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		int a[n];
		int flag=0;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		for(int i=0;i<n;i++)
		{
			if(i==0 && i==n-1 && a[i]==-1)
			{
				cout<<"YES"<<endl<<"1"<<endl;
				flag=1;
				break;
			}
			else if(i==0 && a[i]==-1)
			{
				if(a[i+1]!=1)
				{
					a[i]=1;
				}
				else
				{
					a[i]=2;
				}
			}
			else if(i==n-1 && a[i]==-1)
			{
				if(a[i-1]!=1)
				{
					a[i]=1;
				}
				else
				{
					a[i]=2;
				}
			}
			else if(a[i]==-1 && i!=0 && i!=n-1)
			{
				if(a[i-1]==1)
				{
					if(a[i+1]!=2)
					{
						a[i]=2;
					}
					else
					{
						if(k>=3)
						{
							a[i]=3;
						}
						else
						{
							cout<<"NO"<<endl;
							flag=1;
							break;
						}
					}
				}
				else if(a[i+1]==1)
				{
					if(a[i-1]!=2)
					{
						a[i]=2;
					}
					else
					{
						if(k>=3)
						{
							a[i]=3;
						}
						else
						{
							cout<<"NO"<<endl;
							flag=1;
							break;
						}
					}
				}
				else
				{
					a[i]=1;
				}
			}
		}
		if(flag==0)
		{
			cout<<"YES"<<endl;
		for(int i=0;i<n;i++)
		{
			cout<<a[i]<<" ";
		}
		cout<<endl;
		}
	}
	// your code goes here
	return 0;
}
