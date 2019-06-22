#include <iostream>
using namespace std;
#define ll long long
#define mod 1000000007
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
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin>>n;
    extended_euclid(n,mod);
    cout<<(x+mod)%mod;
}
