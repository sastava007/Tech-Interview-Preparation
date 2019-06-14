#include<stdio.h>
main()
{
register int min,t,l;
int a[5]={64,25,22,12,11},j;
for(int i=0;i<5;i++)
{
min=a[i];
for(j=i;j<5;j++)
    if(a[j]<=min)
    {
      min=a[j];
      l=j;
    }

t=a[i];
a[i]=min;
a[l]=t;
}
for(int k=0;k<5;k++)
printf("%d ",a[k]);

}
