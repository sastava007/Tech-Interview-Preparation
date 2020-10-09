#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);    
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int tc,n,flag,v;
	cin>>tc;
	while(tc--)
	{
		flag=1;
		cin>>n;
		vector<int>a(n);
		vector<int>b(n);
		for(int i=0;i<n;i++)
		{
			a[i]=i+1;
			cin>>b[i];
	    }
	    for(int i=0;i<n;i++)
	    {
	    	if(a[i]!=b[i] && b[i]!=1)
	    	{
	    		v=gcd(a[i],b[i]);
	    		if(v!=b[i])
	    		{
	    			flag=0;
	    			break;
				}
			}
		}
		if(flag==0)
		{
			cout<<"NO"<<endl;
		}
		else
		{
			cout<<"YES"<<endl;
		}
	}
	return 0;
}
