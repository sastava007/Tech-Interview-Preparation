#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define max 100000000
ll mod=1000000007;

bool prime[max]={false};
vector<ll> find_prime()
{
    ll i,j,c=0;

    prime[0]=false;
    prime[1]=false;
    prime[2]=true;

    for(i=3;i<max;i+=2)
        prime[i]=true;


    for(i=3;i*i<max;i+=2)
    {
        if(prime[i])
        {
            for(j=i*i;j<max;j+= 2*i)
            prime[j]=false;
        }

    }
    vector<ll> ans;
    for(i=2;i<max;i++)
    {
       if(prime[i])
        ans.emplace_back(i);
    }
    return ans;
}

// Fast modular exponentiation
ll power(ll a,ll b, ll c)
{
    if(b==0)
        return 1;

    // If b is even then b/2 else a*(b/2)

    ll pre_ans=power(a,b/2,c);
    pre_ans=(pre_ans*pre_ans)%c;
    if(b&1)
        pre_ans=(pre_ans*a)%c;
    return pre_ans;
}


main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n,i;
    cin>>n;
    ll a[n];
    vector<ll> prime=find_prime();
    ll d=1,num=1;
    for(i=0;i<n;i++)
        {
            cin>>a[i];
            d=(d*(a[i]+1)%mod)%mod;
            num=(num*power(prime[i],a[i],mod))%mod;
        }

            if(!(d&1))
            d=power(num,d/2,mod);
            else
            d=(power(num,d/2,mod)*(ll)sqrt(num))%mod;
            cout<<d;

}

