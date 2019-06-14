#include<stdio.h>
main()
{
int n[5],i,j,c=0;
for(i=0;i<5;i++)
scanf("%d",&n[i]);
for(i=0;i<5;i++)
for(j=0;j<5;j++)
if(n[i]>n[j]&&i<j)
{
 printf("%d,%d\n",n[i],n[j]);
 c++;
}

printf("%d",c);
}
