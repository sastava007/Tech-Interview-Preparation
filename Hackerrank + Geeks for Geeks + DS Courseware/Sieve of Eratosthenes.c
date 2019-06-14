#include<stdio.h>
main()
{
int a[100],i,j;
for(i=0;i<100;i++)
a[i]=i+1;

for(i=1;i<100;i++)
{
for(j=0;j<100;j++)
if(a[i]!=0&&a[j]%a[i]==0)
a[j]=0;
}
for(i=0;i<100;i++)
if(a[i]!=0)
printf("%d ",a[i]);


}
