#include<stdio.h>
#include<math.h>
main()
{   long long int a,b;
    int t,j=0,c=0;
    scanf("%d",&t);
    int d[t];
    while(j<t)
    {
        scanf("%lld%lld",&a,&b);
        for(long long int i=a;i<=b;i++)
            if((i!=2||3||7||8)&&(int)sqrt(i)==sqrt(i))
                c++;
       d[j]=c;
        c=0;
        j++;
    }
    for(j=0;j<t;j++)
        printf("%d\n",d[j]);

}
