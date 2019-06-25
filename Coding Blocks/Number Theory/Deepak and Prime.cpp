#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define max 100000000
bool prime[max]={false};
ll find_prime(int n)
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
    for(i=2;i<max;i++)
    {
        if(prime[i])
            c++;
        if(c==n)
            return i;

    }
}

main()
{
    ll n;
    cin>>n;
    cout<<find_prime(n);
}
