#include<stdio.h>
int gcd(int a,int b)
{
for(int i=0;i<5;i++)
if(b!=0)
return gcd(b,a%b);
else
return a;
}
main()
{
int a[5]={-2,4,0,8,16},result=a[0];
for(int i=0;i<4;i++)
result=gcd(result,a[i+1]);
printf("%d",result);



}
