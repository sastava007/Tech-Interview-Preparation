/*
        Summing Sums: https://www.spoj.com/problems/SUMSUMS/
        Used Recurrence relation to find array after Tth operation
        a[i]=(n-2)a[i-1]+(n-1)a[i-2]
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 98765431
ll k=2;
vector<ll> c(2);

vector<vector<ll>> multiply(vector<vector<ll>> a,vector<vector<ll>> b)
{
    vector<vector<ll>> ans(k,vector<ll>(k));
    for(ll i=0;i<k;i++)
        for(ll j=0;j<k;j++)
        for(ll x=0;x<k;x++)
        ans[i][j]=(ans[i][j]+ (a[i][x]*b[x][j])%mod)%mod;
    return ans;

}

vector<vector<ll>> power(vector<vector<ll>> t,ll n)
{
    if(n==1)
        return t;

    if(n&1)
    {
        return multiply(t, power(t,n-1));
    }
    else
    {

        vector<vector<ll> > ans = power(t,n/2);
        return multiply(ans,ans);
    }
}

ll solve(ll n,vector<ll> &b)
{
    if(n==0)
        return b[0];

    // Use matrix exponentiation
    vector<vector<ll>> t(k,vector<ll>(k));

    for(ll i=0;i<k;i++)
    for(ll j=0;j<k;j++)
    {
        if(i<(k-1))
        {
            if(j==(i+1))
            {
                t[i][j] = 1;
            }
            else
                t[i][j] = 0;
            continue;
        }
		else
        t[i][j]=c[k-j-1];
    }

    t=power(t,n);
    ll ans=0;
    for(ll i=0;i<k;i++)
        ans=(ans+(t[0][i]*b[i])%mod)%mod;
    return ans;
}

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n,i;
	ll t;
	cin>>n>>t;
	ll a[n],sum=0;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		sum=(sum+a[i])%mod;
	}
    c[0]=n-2;c[1]=n-1;
	//Apply matrix exponentiation for each element of array
	for(i=0;i<n;i++)
	{
		vector<ll> b(k);
		b[0]=a[i];  b[1]=(sum-a[i])%mod;
		ll ans=solve(t,b);
		// also consider the case when n=1 because in that case a[i]'=sum-a[i] which will become zero
		if(ans<0)
            ans+=mod;
		cout<<ans<<"\n";
	}
}
