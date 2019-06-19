#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll k,mod;

vector<vector<ll>> multiply(vector<vector<ll>> a,vector<vector<ll>> b)
{
    vector<vector<ll>> ans(k+1,vector<ll>(k+1));
    for(ll i=0;i<k+1;i++)
        for(ll j=0;j<k+1;j++)
        for(ll x=0;x<k+1;x++)
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

ll solve(ll n,vector<ll> &b,vector<ll> &c)
{
    if(n==0)
        return 0;
    if(n<=k)
        return b[n];

    // Use matrix exponentiation
    vector<vector<ll>> t(k+1,vector<ll>(k+1));

    for(ll i=0;i<k+1;i++)
    for(ll j=0;j<k+1;j++)
    {
        if(i==0 && j==0)
        {
            t[i][j]=1;
            continue;
        }

        if(i==k)
        {
            t[i][j]=c[k-j];
            continue;
        }
        if(j==i+1)
        {
            t[i][j]=1;
            continue;
        }
        else
            t[i][j]=0;
    }

    t=power(t,n);
    ll ans=0;
    for(ll i=0;i<k+1;i++)
        ans=(ans+(t[0][i]*b[i])%mod)%mod;
    return ans;

}
main()
{
    ll t,n,m,i;
    cin>>t;
    while(t--)
    {

        cin>>k;
        vector<ll> b(k+1),c(k+1);

        // S[0]=0
        b[0]=0;
        for(i=1;i<k+1;i++)
            {
                cin>>b[i];
            }

        for(i=0;i<k;i++)
            {
                cin>>c[i];
            }
            c[k]=0;

        cin>>m>>n>>mod;

        ll ans=solve(n,b,c)-solve(m-1,b,c);
        if(ans<0)
            ans+=mod;
        cout<<ans<<"\n";
    }

}
