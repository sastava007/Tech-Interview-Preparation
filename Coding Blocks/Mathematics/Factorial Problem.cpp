/*
    https://math.stackexchange.com/questions/642216/factorials-and-prime-factors
    if k is a prime number, then maximum power of k such that k^x divides n! is given by floor(n/p) + floor(n/p2) + floor(n/p3) + ......
    and this is known as Legendre's Theorem: Prime Factorization of factorials

#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll power(ll a,ll b)
{
    if(b==0)
        return 1;

    ll pre_ans=power(a,b/2);
    pre_ans=(pre_ans*pre_ans);
    if(b&1)
        pre_ans=(pre_ans*a);
    return pre_ans;
}

ll solve(ll n,ll k)
{
    ll i=1;
    ll ans=floor(n/power(k,i));
    ll x;
    x=ans;

    while(ans!=0)
    {
        i++;
        ans=floor(n/power(k,i));
        x+=ans;
    }
    return x;
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
        cout<<solve(n,k)<<"\n";
    }
}
*/

// But in this question k need not be a prime number, so k will only divide n if order of prime factors in k is less than that of n
// Note: All the prime factors of n! are always <=n

#include<bits/stdc++.h>
#define ll long long
using namespace std;
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        ll ans=LONG_MAX;
        ll n,k;
        cin>>n>>k;
        for(ll i=2;i*i<=k;i++)
        {
            if(k%i==0)
            {
                ll p=0;
                while(k%i==0)
                {
                    p++;
                    k/=i;
                }
                ll j=i,c=0;
                while(j<=n)
                {
                    c+=n/j;
                    j*=i;
                }
                ans=min(ans,c/p);
            }
        }
        if(k>1)
        {
            ll c=0,j=k;
            while(j<=n)
            {
                c+=n/j;
                j*=k;
            }
            ans=min(ans,c);
        }
        ans!=LONG_MAX?cout<<ans<<"\n":cout<<"0\n";
    }
}
