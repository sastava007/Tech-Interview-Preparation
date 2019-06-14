#include<stdio.h>
main()
{
int a[8]={1,2,3,4,5,6,7,8};
int c=0;
for(int i=0;i<8;i++)
for(int j=i+1;j<8;j++)
for(int k=j+1;k<8;k++)
if(a[i]*a[i]==a[j]*a[j]+a[k]*a[k]||a[j]*a[j]==a[i]*a[i]+a[k]*a[k]||a[k]*a[k]==a[j]*a[j]+a[i]*a[i])
{
c++;
/*a[k]=0;
a[i]=0;
a[j]=0;*/
printf("%d%d%d",a[i],a[j],a[k]);
}
printf("\n%d",c);
}


