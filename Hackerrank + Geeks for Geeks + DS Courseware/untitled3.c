#include<stdio.h>
int main()
{
    int t,r,l;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&l,&r);
        int s1=r*r;
        int s2=(l-1)*(l-1);
        printf("%d",s1-s2);
    }
    return 0;
}
