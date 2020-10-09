#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000000

ll k=3;
vector<ll> b(k),c(k);

vector<vector<ll>> multiply(vector<vector<ll>> a,vector<vector<ll>> b)
{
    vector<vector<ll>> ans(k,vector<ll>(k));
    for(ll i=1;i<k;i++)
        for(ll j=1;j<k;j++)
        for(ll x=1;x<k;x++)
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

ll solve(int n)
{
    if(n<k)
        return b[n];

    vector<vector<ll>> t(k,vector<ll>(k));

    for(ll i=1;i<k;i++)
    for(ll j=1;j<k;j++)
    {
        if(i<(k-1))
        {
            if(j==i+1)
                t[i][j]=1;
            else
                t[i][j]=0;
        }
        else
            t[i][j]=c[k-j];
    }

    t=power(t,n-1);
    ll ans=0;
    for(ll i=1;i<k;i++)
        ans=(ans + (t[1][i]*b[i])%mod)%mod;
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    b[1]=1;b[2]=1;
    c[1]=1;c[2]=1;

    ll t;
    cin>>t;

    while(t--)
    {
        ll n;
        cin>>n;
        cout<<solve(n)<<"\n";
    }
    return 0;
}
// wapas se kar raha