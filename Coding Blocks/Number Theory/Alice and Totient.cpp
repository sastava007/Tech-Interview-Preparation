#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> prime_sieve(ll n)
{
    vector<bool> prime(n,false);
    for(ll i=3;i<n;i+=2)
        prime[i]=true;
    for(ll i=3;i*i<n;i+=2)
    for(ll j=i*i;j<n;j+=2*i)
    {
        if(prime[j])prime[j]=false;
    }
    prime[2]=true;
    vector<ll> ans;
    for(ll i=2;i<n;i++)
        if(prime[i])
        ans.push_back(i);
    return ans;
}

unordered_set<ll> factorize(ll n)
{
    ll i=0;
    vector<ll>prime=prime_sieve(n);
    ll p=prime[i];
    unordered_set<ll>factors;
    while(p*p<=n)
    {
        while(n%p==0)
        {
            factors.insert(p);
            n/=p;
        }
        i++;
        p=prime[i];
    }
    if(n>1)
        factors.insert(n);
    return factors;
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        unordered_set<ll> factors=factorize(n);
        if(factors.size()==0)
        cout<<n-1<<"\n";
        else
        {
            ll ans=n;
            for(auto it:factors)
             ans=ans*(1-(double)1/it);
             cout<<(ll)ans<<"\n";
        }

    }
}
