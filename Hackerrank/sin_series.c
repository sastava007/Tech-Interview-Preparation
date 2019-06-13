#include<stdio.h>
#include<math.h>
int i=1,p=1;
float s=0;
int fact(int n)
{
 if(n>0)
return n*fact(n-1);
else
return 1;
}

float series(float x,int n)
{
if(i<=n)
{
s=s+ pow(-1,i-1)*pow(x,2*i-1)/fact(2*i-1);
i++;
series(x,n);
}
return s;
}
main()
{
float x;
int n;
scanf("%f%d",&x,&n);
printf("%f",series(x,n));
}
