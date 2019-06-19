/*
                        Spoj: https://www.spoj.com/problems/SEQ/
                        Solved using matrix exponentiation
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000000

vector<ll> b,c;
ll k;

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

ll solve(ll n)
{
    if(n==0)
        return 0;
    if(n<=k)
        return b[n-1];

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

        t[i][j]=c[k-j-1];
    }

    t=power(t,n-1);
    ll ans=0;
    for(ll i=0;i<k;i++)
        ans=(ans+(t[0][i]*b[i])%mod)%mod;
    return ans;

}
main()
{
    ll t,n,i,num;
    cin>>t;
    while(t--)
    {
        cin>>k;

        for(i=0;i<k;i++)
            {
                cin>>num;
                b.push_back(num);
            }

        for(i=0;i<k;i++)
            {
                cin>>num;
                c.push_back(num);
            }

        cin>>n;

        cout<<solve(n)<<"\n";
        b.clear();
        c.clear();
    }

}

