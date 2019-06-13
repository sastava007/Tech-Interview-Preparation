#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool powerof10(ll n)
{
    double x=log10(n);
    ll y=(ll)x;
    return x==y;
}

ll solve(ll n)
{
    ll ans=10+9*n;
    if(powerof10(ans))
        ans=19+9*n;
    return ans;
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<powerof10(n)<<"\n";
    }
}

