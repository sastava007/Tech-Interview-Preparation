#include<stdio.h>
main()
{
    int n;
    int i;
    scanf("%d",&n);
    int a[n],f[100]={0};
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        f[a[i]]++;
    }
    for(i=0;i<100;i++)
    {
        for(int j=0;j<f[i];j++)
            printf("%d ",i);
    }
}
