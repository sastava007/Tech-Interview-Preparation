#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

ll x,y;
void multiplicative_inverse(ll a, ll m)
{
    if(m==0)
    {
        x=1;
        y=0;
        return;
    }
    else
    {
        multiplicative_inverse(m,a%m);
        ll Cx=y;
        ll Cy=x-(a/m)*y;
        x=Cx;
        y=Cy;
    }
}
main()
{
    ll n;
    cin>>n;
    multiplicative_inverse(n,mod);
    cout<<(x+mod)%mod;
}
