#include<stdio.h>
int i=2,j=2;
void prime(int n)
{
int c=0;
if(i<n)
{
if(j<i)
{
if(i%j==0)
{
c++;
}
j++;
if(c==0)
prime(n);
}
if(c==0&&n%i==0&&n!=i)
printf("%d ",i);
i++;
j=2;
prime(n);
}
}
main()
{
int n;
scanf("%d",&n);
prime(n);
}
