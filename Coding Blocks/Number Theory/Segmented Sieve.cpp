#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<bool> sieve(int n)
{
    vector<bool> prime(n,false);
    for(int i=3;i<n;i+=2)
        prime[i]=true;
    for(int i=3;i<n;i+=2)
    {
        for(int j=i*i;j<n;j+=2*i)
            if(prime[j])
                prime[j]=false;
    }
    prime[2]=true;
    return prime;
}

vector<bool> segmented_sieve(ll a,ll b)
{
    int n=sqrt(b);
    vector<bool> prime=sieve(n);

    vector<bool> ans(b-a+1,true);
    for(int i=2;i<=n;i++)
    {
        if(prime[i])
        for(int j=a;j<=b;j++)
        {
            if(j%i==0 && j!=i)
            ans[j-a]=false;
        }
    }
    return ans;
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll a,b;
    cin>>a>>b;
    vector<bool> prime=segmented_sieve(a,b);
    for(int i=0;i<(b-a+1);i++)
        if(prime[i])cout<<a+i<<" ";

}
