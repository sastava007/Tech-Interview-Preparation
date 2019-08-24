#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

#define mod1 1000000
#define mod2 1000000007

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
    while(p*p<=n)
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
int pairCount(int n, int k)
{
    if (k == 0 || k == n)
        return 1;
    return (pairCount(n - 1, k - 1) + pairCount(n - 1, k))%mod2;
}

int getSubsets(int k, int n, vector<int> arr) {
    int i;
    int sum=0;
    for(i=0;i<n;i++)
    {
        if(arr[i]==1)
        {
            sum+=0;
        }
        else if(arr[i]==2)
            sum+=2;
        else
        {
            vector<int>prime_factors=factorize(arr[i]);
            for(auto it:prime_factors)
                sum=(sum+it)%mod1;
        }

    }
    return pairCount(sum+k-1,k-1);

}

main()
{
    vector<int> v{1,2,6};
    cout<<getSubsets(2,3,v);
}
