/*
        FIBOSUM: F(m)+F(m+1)+F(m+2)+F(m+3)+.......F(n)
        can be calculated using prefix sum which is Sum(i)=F(i+2)-1 //by observation
        After this just subtract Sum(n)-Sum(m-1) to get sum of above series
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

ll k=2;
vector<ll> b(k),c(k);

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

ll solve(int n)
{
    if(n==0)
        return 0;
    if(n<k)
        return b[n];

    vector<vector<ll>> t(k,vector<ll>(k));

    for(ll i=0;i<k;i++)
    for(ll j=0;j<k;j++)
    {
        if(i<(k-1))
        {
            if(j==i+1)
                t[i][j]=1;
            else
                t[i][j]=0;
        }
        else
            t[i][j]=c[k-j-1];
    }

    t=power(t,n-1);
    ll ans=0;
    for(ll i=0;i<k;i++)
        ans=(ans + (t[0][i]*b[i])%mod)%mod;
    return ans;
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    b[0]=1;b[1]=1;
    c[0]=1;c[1]=1;

    ll t;
    cin>>t;

    while(t--)
    {
        ll m,n;
        cin>>m>>n;
        ll sum_n=solve(2+n)-1;
        ll sum_m=solve(1+m)-1;

        ll ans=sum_n-sum_m;
        if(ans<0)
            ans+=mod;
        cout<<ans<<"\n";

    }
}
