// Time complexicity: O(n log(log(n))) which is same as simple sieve , we only use this because we can't declare array of so long

#include<bits/stdc++.h>
using namespace std;
void sieve(int a[],int n)
{
    int i,j;
    for(i=3;i<n;i+=2)
        a[i]=1;
    for(i=3;i<n;i+=2)
        for(j=i*i;j<n;j+=i)
        if(a[j])
        a[j]=0;
    a[0]=0;
    a[1]=0;
    a[2]=1;
}
void segmented_sieve(long long int a,long long int b)
{
    //to find prime numbers between 0 and <=sqrt(b)
    int n=sqrt(b);
    int prime[n];
    sieve(prime,n);


    bool pp[b-a+1];
    memset(pp,true,sizeof(pp));
    for(long long int i=2;i<=n;i++)
        for(long long int j=a;j<=b;j++)
        {
            // now mark the multiples of these prime numbers which lie in between 'a' and 'b'
            if(prime[i])
            {
                if(i==j)
                continue;
                if(j%i==0)
                pp[j-a]=false;
            }
        }
    for(int k=0;k<(b-a+1);k++)
        if(pp[k])
        cout<<k+a<<endl;
}
main()
{
    long long int a,b;
    cin>>a>>b;
    segmented_sieve(a,b);


}
