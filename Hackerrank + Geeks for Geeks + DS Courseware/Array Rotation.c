#include<stdio.h>
void main()
{
int d,n,i;
scanf("%d%d",&n,&d);
int a[n],t[n-d];
for(i=0;i<n;i++)
scanf("%d",&a[i]);
for(i=0;i<n-d;i++)
{
    t[i]=a[i];
    a[i]=a[i+2];

}
for(i=0;i<n-d;i++)
a[n-d+i]=t[i];
   for(i=0;i<n;i++)
   printf("%d",a[i]);
}
