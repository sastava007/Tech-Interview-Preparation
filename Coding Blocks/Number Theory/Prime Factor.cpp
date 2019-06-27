#include<bits/stdc++.h>
using namespace std;

// This will return all prime no less than n
vector<int> prime_sieve(int n)
{
    vector<bool> prime(n,false);
    for(int i=3;i<n;i+=2)
        prime[i]=true;
    for(int i=3;i*i<n;i+=2)
    for(int j=i*i;j<n;j+=2*i)
    {
        if(prime[j])prime[j]=false;
    }
    prime[2]=true;
    vector<int> ans;
    for(int i=2;i<n;i++)
        if(prime[i])
        ans.push_back(i);
    return ans;
}

vector<int> factorize(int n)
{
    int i=0;
    vector<int>prime=prime_sieve(n);
    int p=prime[i];
    vector<int>factors;
    while(p*p<=n)3
    {
        while(n%p==0)
        {
            factors.push_back(p);
            n/=p;
        }
        i++;
        p=prime[i];
    }
    if(n>1)
        factors.push_back(n);
    return factors;
}
main()
{
    int n;
    cin>>n;
    vector<int>prime_factors=factorize(n);
    for(auto i:prime_factors)
    cout<<i<<" ";
}
