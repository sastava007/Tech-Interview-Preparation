#include<stdio.h>
main()
{
    int t,n,k,v,i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&k,&v);
        long long int a[n],s=0;
        for(i=0;i<n;i++)
        {
           scanf("%d",&a[i]);
            s+=a[i];
        }
        if((v*(n+k)-s)%n==0)
            printf("%d\n",(v*(n+k)-s)/n);
        else
            printf("-1\n");
    }

}
