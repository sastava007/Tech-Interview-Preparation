// Here k=3 for this problem
// https://www.geeksforgeeks.org/count-ways-reach-nth-stair-using-step-1-2-3/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000000

vector<vector<ll>> multiply(vector<vector<ll>> a,vector<vector<ll>> b)
{
    vector<vector<ll>> ans(4,vector<ll>(4));
    for(ll i=1;i<4;i++)
        for(ll j=1;j<4;j++)
        for(ll x=1;x<4;x++)
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
    vector<ll> b(4);
    b[1]=1;b[2]=2;b[3]=4;

    vector<ll> c(4);
    c[1]=1;c[2]=1;c[3]=1;

    if(n<0)
        return 0;
    if(n<4)
        return b[n];

    vector<vector<ll>> t(4,vector<ll>(4));

    for(ll i=1;i<4;i++)
    for(ll j=1;j<4;j++)
    {
        if(i<3)
        {
            if(j==i+1)
                t[i][j]=1;
            else
                t[i][j]=0;
        }
        t[i][j]=c[4-j];
    }

    t=power(t,n-1);
    ll ans=0;
    for(ll i=1;i<4;i++)
        ans+=(t[1][i]*b[i]);
    return ans;
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    cout<<solve(n);
}
