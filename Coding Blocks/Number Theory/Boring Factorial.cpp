// To calculate n! mod p and 'n' and 'p' are of 10^9 order

#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll power(ll a,ll b, ll c)
{
    if(b==0)
        return 1;

    // If b is even then b/2 else a(b/2)

    ll pre_ans=power(a,b/2,c);
    pre_ans=(pre_ans*pre_ans)%c;
    if(b&1)
        pre_ans=(pre_ans*a)%c;
    return pre_ans;
}

ll solve(ll n,ll p){
    ll ans = 1;
    for(ll i=(n+1);i<=(p-1);i++){
        ll temp = power(i,p-2,p);
        ans = (ans*temp)%p;
    }
    return (ans*(p-1))%p;
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    ll n,p;
    cin>>t;
    while(t--)
    {
        cin>>n>>p;
        if(n>=p)
            cout<<"0\n";
        else
            cout<<solve(n,p)<<"\n";
    }
}
