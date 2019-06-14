#include<stdio.h>
int prime(int n)    //func to check whether a given no is prime or not
{
int c=0,i;
for(i=2;i<n;i++)
{
if(n%i==0)
c++;
}
if(c==0)
return 1;
}


int check(int n)                //func to check that whether that no can be written as sum of 2 semi prime or not
{
for(int x=0;x<n;x++)
for(int y=0;y<n;y++)
if(n==x*y&&prime(x)==1&&prime(y)==1&&(x!=y))
return 1;
}

main()
{
    int t=1;
    scanf("%d",&t);
    while(t--)
    {

int n,c=0;
scanf("%d",&n);
for(int i=1;i<n;i++)
for(int j=1;j<n;j++)
if(i+j==n&&check(i)==1&&check(j)==1)
c++;
if(c!=0)
printf("Yes");
else
printf("No");
    }
}
