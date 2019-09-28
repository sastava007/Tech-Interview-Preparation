#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define deb(x) cout<<#x<<" "<<x<"\n"

vector<ll> v;
void solve(ll n)
{
//    if(n<=1)
//    {
//        v.emplace_back(n);
//        return;
//    }
    if(n==0)
        return;
    if(n==1)
    {
        v.emplace_back(1);
        return;
    }
    solve(n/2);
    solve(n%2);
    solve(n/2);kk
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,l,r;
    cin>>n>>l>>r;
    solve(n);

    ll c=0;
    for(;l<=r;l++)
        if(v[l-1]==1)
        c++;
    cout<<c;
}
