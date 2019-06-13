#include<stdio.h>
main()
{
    long long int t,n,k,v,i;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%lld%lld",&n,&k,&v);
        long long int a[n],s=0;
        for(i=0;i<n;i++)
        {
           scanf("%lld",&a[i]);
            s+=a[i];
        }
        if((v*(n+k)-s)%k==0&&(v*(n+k)-s)>0)
            printf("%d\n",(v*(n+k)-s)/k);
        else
            printf("-1\n");
    }

}
