#include<bits/stdc++.h>
using namespace std;
void check_prime(int *prime,int b)
{
    for(int i=2;i*i<=b;i++)
    {
        if(prime[i-2]!=-1)
        {
        for(int j=i*i;j<=b;j+=i)
        prime[j]=-1;
        }
    }
}

int main()
{
    int a,b,i,j,q,c=0,rem=0,s;
    cin>>a>>b;
    int prime[b+1];
    for(i=0;i<b+1;i++)
    prime[i]=0;
    check_prime(prime,b);
    for(i=a;i<=b;i++)
    {
        if(prime[i]!=-1)
        {
            q=i,rem=0,s=0;
            while(q!=0)
            {
                rem=q%10;
                s+=rem;
                q/=10;
            }
            if(s%2!=0||s==2)
            cout<<i<<" ";
        }
    }
return 0;
}
