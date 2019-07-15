/*
    Simple Tiling Problem https://practice.geeksforgeeks.org/problems/number-of-ways
    Using linear DP f(n)=f(n-1)+f(n-4)

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll compute(int n)
{
    ll res[n+1];
    res[1]=1;res[2]=1;res[3]=1;
    res[4]=2;

    if(n<5)
    return res[n];
    for(int i=5;i<=n;i++)
    res[i]=res[i-1]+res[i-4];
    return res[n-1]+res[n-4];
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<compute(n)<<"\n";
    }
}
/*
    More generalised version of tiling problem
    here f(n)=f(n-1) +f(n-m) ; n>m

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

ll compute(ll n,ll m)
{
    ll res[n+1],i;
    for(i=1;i<=n;i++)
    {
        if(i<m)
        res[i]=1;
        else if(i==m)
        res[i]=2;
        else
        res[i]=(res[i-1]+res[i-m])%mod;
    }
    return res[n];
}
main()
{
	int t;
	ll n,m;
	cin>>t;
	while(t--)
	{
		 cin>>n>>m;
    	cout<<compute(n,m)<<"\n";
	}


}
