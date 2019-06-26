#include<bits/stdc++.h>
using namespace std;
#define ll long long
// for n primes upto 10^5 modify as per need
#define max 10000000

bool prime[max]={false};
vector<ll> find_prime()
{
    ll i,j,c=0;

    prime[0]=false;prime[1]=false;prime[2]=true;

    for(i=3;i<max;i+=2)
        prime[i]=true;

    for(i=3;i*i<=max;i+=2)
    {
        if(prime[i])
        {
            for(j=i*i;j<=max;j+=(2*i))
            prime[j]=false;
        }

    }
    vector<ll> ans={0};
    for(i=2;i<max;i++)
    if(prime[i])
    ans.emplace_back(i);
    return ans;
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n,t;
    cin>>t;
    vector<ll>prime=find_prime();
    while(t--)
    {
     cin>>n;
     cout<<prime[n]<<"\n";
    }

}
