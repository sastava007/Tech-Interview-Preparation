#include<stdio.h>
main()
{
int l=0,d=1,c=0;
int a[5];
for(int i=0;i<5;i++)
scanf("%d",&a[i]);
for(int i=2;i<=5;i++)
{
l=a[0]+ (i-1)*d;
if(l!=a[i-1])
c++;
}
printf("%d",c);

}
