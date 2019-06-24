#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll fastexpo(ll a, ll b, ll m)
{
    ll ans=1;
    while(b>0)
    {
        if(b&1)
            ans=(ans*a)%m;
        a=(a*a)%m;
        b=b>>1;
    }
    return ans;
}
main()
{
   ll a, b, m;
   cin>>a>>b>>m;
   cout<<fastexpo(a,b,m);
}
