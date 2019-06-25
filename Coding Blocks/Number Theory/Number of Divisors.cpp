/*
        Find number of divisors of a number n which is obtained by product of all elements of array
        https://www.geeksforgeeks.org/count-divisors-array-multiplication/
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
vector<bool> find_prime(int n)
{
    int i,j;
    vector<bool> prime(n,false);
    prime[0]=false;
    prime[1]=false;
    prime[2]=true;
    for(i=3;i<n;i+=2)
        prime[i]=true;


    for(i=3;i*i<n;i+=2)
    {
        if(prime[i])
        for(j=i*i;j<n;j+= 2*i)
            prime[j]=false;
    }

    return prime;
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,i,n,j;
    cin>>t;
    while(t--)
    {
        cin>>n;
        ll a[n];
        for(i=0;i<n;i++)
            cin>>a[i];
        ll max_ele=*max_element(a,a+n);
        vector<bool> prime=find_prime(max_ele);

        unordered_map<ll, ll> m;
        for(i=0;i<n;i++)
        {
            for(j=2;j<prime.size();j++)
                {
                    while(prime[j] && a[i]%j==0)
                    {
                        m[j]++;
                        a[i]/=j;
                    }
                }
                if(a[i]>1)
                    m[a[i]]++;
        }
        ll ans=1;
        for(auto it:m)
         ans=(ans*(it.second+1ll))%mod;

        cout<<ans<<"\n";
    }
}

