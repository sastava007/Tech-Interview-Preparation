#include<stdio.h>
main()
{
int n,s;
scanf("%d",&n);
for(int i=0;i<n;i++)
{
for(int j=0;j<n-1-i;j++)
printf(" ");
//int c=0;
for(int k=0;k<=i;k++)
{
    s=k;
printf("%d",s);
s--;
}
s=s+1;
for(int l=0;l<i;l++)
{
printf("%d",s);
s++;
}
printf("\n");
}








}
