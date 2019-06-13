#include<stdio.h>
main()
{
register int t;
int a[5]={8,5,4,2,1};
for(int i=0;i<5;i++)
for(int j=0;j<4;j++)
if(a[j]>a[j+1])
{
t=a[j];
a[j]=a[j+1];
a[j+1]=t;
}
for(int k=0;k<5;k++)
printf("%d ",a[k]);

}
