#include<bits/stdc++.h>
#define ll unsigned long long
#define mod 1000000009
using namespace std;

ll exponentiation(ll A, ll B,mod)
{
    // Base cases
    if (A == 0)
        return 0;
    if (B == 0)
        return 1;

    // If B is even
    ll y;
    if (B % 2 == 0) {
        y = exponentiation(A, B / 2, mod);
        y = (y * y) % C;
    }

    // If B is odd
    else {
        y = A % mod;
        y = (y * exponentiation(A, B - 1, mod) % mod) % mod;
    }

    return (ll)((y + mod) % mod);
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,k,i;
    cin>>t;

    while(t--)
    {
        cin>>k;
        ll pre_ans=exponentiation(2,k-1,mod);
        ll ans=(10*pre_ans)%mod;
        cout<<ans<<"\n";
    }

}
