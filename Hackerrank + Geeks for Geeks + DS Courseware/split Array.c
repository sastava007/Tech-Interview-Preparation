#include<stdio.h>
main()
{
int a[6]={1,2,3,4,5,6};
for(int i=0;i<6/2;i++)
{
int t=a[i];
a[i]=a[6/2+i];
a[6/2+i]=t;
}
for(int i=0;i<6;i++)
printf("%d",a[i]);
}



