#include<stdio.h>
main()
{
    int t;
    scanf("%d",&t);
    long long int n[t],rem,q,c;

    int d[t],j=0;
    while(j<t)
    {
       scanf("%lld",&n[j]);
        c=0;
        q=n;
      while(q!=0)
       {
          rem=q%10;
        q/=10;
         if(rem!=0)
             if(n[j]%rem==0)
             c++;
       }
      d[j]=c;
      j++;
    }
    for(j=0;j<t;j++)
        printf("%d\n",d[j]);

}
