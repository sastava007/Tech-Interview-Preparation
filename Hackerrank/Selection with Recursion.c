#include<stdio.h>
int i=0,j=0,l,t,min;
void selection(int *a,int n)
{
if(i<n)
  {
  if(j<n)
    {
     if(a[j]<=min)
     {
     min=a[j];
     l=j;
     }
     j++;
     selection(a,n);
    }
    t=a[i];
    a[i]=min;
    a[l]=t;
    i++;
    j=i;
    l=i;
    min=a[i];
    selection(a,n);
  }
}
main()
{
int a[5]={5,1,4,2,8},n=5;
min=a[0];
selection(a,n);
for(int k=0;k<n;k++)
printf("%d ",a[k]);
}
