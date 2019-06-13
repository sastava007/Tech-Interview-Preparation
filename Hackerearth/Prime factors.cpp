#include<bits/stdc++.h>
using namespace std;
vector<int> sieve(int n)
{
    int i,j;
    bool prime[n+1]={false};
    for(i=3;i<=n;i+=2)
        prime[i]=true;
    prime[0]=false;
    prime[1]=false;
    prime[2]=true;

    for(i=3;i<=n;i+=2)
    {
        for(j=i*i;j<=n;j+=2*i)
            if(prime[j])
            prime[j]=false;
    }

    vector<int> prime_no;
    for(i=2;i<=n;i++)
        if(prime[i])
        prime_no.push_back(i);
    return prime_no;
}

vector<int> prime_factors(int n)
{
   vector<int> prime;
   prime.clear();
    prime=sieve(n);

    int i=0;
    vector<int> factors;
    while(i<=sqrt(n))
    {
        if(n%prime[i]==0)
        {
            factors.push_back(prime[i]);
            while(n%prime[i]==0)
                n=n/prime[i];
        }

        i++;
    }
    if(n!=1)
      factors.push_back(n);
    return factors;
}
main()
{
        int n;
        cin>>n;
        vector<int> factors=prime_factors(n);
        for(auto i:factors)
            cout<<i<<" ";
}
