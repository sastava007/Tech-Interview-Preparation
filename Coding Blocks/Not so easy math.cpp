#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb(x) push_back(x)

ll final_ans=0;
void solve(ll n,ll *a,ll x)
{
    vector<ll> ans;
    ll i=0;
    while(n>0)
    {
        if(n&1)
            ans.pb(a[i]);
        i++;
        n=n>>1;
    }
    ll l=ans.size();
    ll p=1ll;
    for(i=0;i<l;i++)
    {
       p*=ans[i];
    }
    ll temp=floor(x/p);
    if(l&1)
        final_ans+=temp;
    else
        final_ans-=temp;
}
main()
{
    ll t,n;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>t;
    ll range =(1<<8),i;
    ll prime[]={2,3,5,7,11,13,17,19};

    while(t--)
    {
        cin>>n;
        for(i=1;i<range;i++)
        {
            solve(i,prime,n);
        }
        cout<<final_ans<<"\n";
        final_ans=0;
    }

}
