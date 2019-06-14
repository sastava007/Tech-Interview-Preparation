#include<stdio.h>
main()
{
int n,i,j;
scanf("%d",&n);
int a[n];
for(i=0;i<n;i++)
scanf("%d",&a[i]);
for(i=0;i<n;i++)
{
int c=0;
for(j=i+1;j<n;j++)
if(a[i]==a[j])
c++;

if(c==0)
printf("%d",a[i]);
}
}
