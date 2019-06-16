/*
                            Marbles Problem using Star and Bar principle
                            Spoj: https://www.spoj.com/problems/MARBLES/
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll bar_star(ll n,ll k)
{
    ll ans=1ll;
    if(n==k)
        return ans;
    k=min(n-k,k);
    for(ll i=0;i<k;i++)
        ans=(ans*(n-i))/(i+1);
    return ans;
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
        cout<<bar_star(n-1,k-1)<<"\n";
    }
}
