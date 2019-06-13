#include<stdio.h>
void roman(int n)
{
int q=n,m,d,c,l,x,v,ile,j;
m=q/1000;
q=q%1000;
d=q/500;
q=q%500;
c=q/100;
q=q%100;
l=q/50;
q=q%50;
x=q/10;
q=q%10;
v=q/5;
q=q%5;
ile=q;
for(j=0;j<m;j++)
printf("M");
for(j=0;j<d;j++)
printf("D");
for(j=0;j<c;j++)
printf("C");
for(j=0;j<l;j++)
printf("L");
for(j=0;j<x;j++)
printf("X");
for(j=0;j<v;j++)
printf("V");
for(j=0;j<ile;j++)
{
if(ile<=3)
printf("I");
else if(ile==4)
printf("IV");
else if(ile==6)
printf("VI");
}
}
main()
{
int n;
scanf("%d",&n);
roman(n);

}
