#include<bits/stdc++.h>
using namespace std;
int count_one(long long int n)
{
    int c=0;
    while(n)
    {
        n=n&(n-1);
        c++;
    }
    return c;
}

main()
{
    int t,n,q,i,j,k,start,curr_sum,diff;
    scanf("%d%d",&n,&q);

    long long int a[n],setbits[n];
    for(i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
        setbits[i]=count_one(a[i]);
    }
    while(q--)
    {
        cin>>k;
        start=0,curr_sum=0,diff=n+1;
        for(i=0;i<n;i++)
        {
            curr_sum+=setbits[i];
             while(curr_sum>=k)
            {
                diff=min(diff,i-start+1);
                curr_sum-=setbits[start++];
            }
        }
        if(diff!=n+1)
            printf("%d\n",diff);
        else
            printf("-1\n");

    }

}
