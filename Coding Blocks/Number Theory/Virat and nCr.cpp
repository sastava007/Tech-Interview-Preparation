#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 1000000
#define mod 1000000007
ll fac[MAX+1];
ll x,y;

ll power(ll a,ll b, ll c)
{
    if(b==0)
        return 1;

    // If b is even then b/2 else a*(b/2)

    ll pre_ans=power(a,b/2,c);
    pre_ans=(pre_ans*pre_ans)%c;
    if(b&1)
        pre_ans=(pre_ans*a)%c;
    return pre_ans;
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n,i,r;
    cin>>n>>r;
    fac[0]=1;

    for(i=1;i<=n;i++)
        fac[i]=(fac[i-1]*i)%mod;

    ll temp1=fac[r];
    ll temp2=fac[n-r];
    temp1=power(temp1,mod-2,mod);
    temp2=power(temp2,mod-2,mod);

    ll ans=((fac[n]%mod)*(temp1%mod)*(temp2%mod))%mod;
    cout<<ans;

}

