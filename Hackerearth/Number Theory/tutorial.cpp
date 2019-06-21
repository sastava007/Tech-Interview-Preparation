#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll power(ll a, ll b, ll m)
{
    if(b==0)
    return 1;
    ll ans=power(a,b/2,m);
    ans=(ans*ans)%m;
    if(b&1)
    ans=(ans*a)%m;
    return ans;
}

ll x,y;
void extended_euclid(ll a,ll m)
{
    //base case
    if(m==0)
    {
        x=1;
        y=0;
        return;
    }
    //recursive case
    extended_euclid(m,a%m);
    ll cx=y;
    ll cy=x-(a/m)*y;

    x=cx;
    y=cy;
}
main()
{
    ll a,b,c,m;
    cin>>a>>b>>c>>m;
    ll ans1=power(a,b,m);

    extended_euclid(c,m);
    ll ans2=(x+m)%m;

    cout<<(ans1*ans2)%m;
}
