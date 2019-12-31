#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define deb(x) cout<<#x<<" "<<x<"\n"
#define mod 1000000007

ll f[1000003];

void fac()
{
//  ll f[n+1];
  ll i;
  f[0]=1;

  for(i=1;i<=1000002;i++)
    f[i]=(i*f[i-1])%mod;
}

ll ans[1000003];


void solve()
{
    ll i;
    ans[1]=1;
    ans[2]=2;

    for(i=3;i<=1000002;i++)
    ans[i]=(f[i]*ans[i-1])%mod;

}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t,n,i,j;
    cin>>t;
    fac();
    solve();
    while(t--)
    {
        cin>>n;

        cout<<ans[n]<<"\n";
    }

}
