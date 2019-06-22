#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

ll stringToInt(string a, ll p)
{
    ll ans=0;
    for(ll i=0;i<a.length();i++)
        ans=((ans*10)%p+(a[i]-'0'))%p;
    return ans;
}
// Fast modular exponentiation
ll power(ll a,ll b, ll m)
{
    if(b==0)
        return 1;
    ll ans=power(a,b/2,m);
    ans=(ans*ans)%m;
    if(b&1)
        ans=(ans*a)%m;
    return ans;
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin>>t;
    string a,b;
    while(t--)
    {
        cin>>a>>b;
        ll A=stringToInt(a,mod);
        ll B=stringToInt(b,mod-1);
        cout<<power(A,B,mod)<<"\n";
    }
}
