#include<stdio.h>
main()
{
int a[5],i,max=0,max2=0;
for(i=0;i<5;i++)
{
scanf("%d",&a[i]);
if(a[i]>max)
max=a[i];
}

for(i=0;i<5;i++)
{
if(a[i]!=max)
{
if(a[i]>max2)
max2=a[i];
}
}
printf("%d",max2);
}
