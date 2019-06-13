#include<stdio.h>
int delete(int *a,int i,int n)
{
for(int j=n-1-i;j<n-1;j++)
a[j]=a[j+1];
return a;
}
main()
{
int n=8,c=0,i;
int a[8]={1,3,5,7,9,5,2,4};
for(i=0;i<n;i++)
if(a[i]==5)
c++;
while(c==0)
{
    for(i=0;i<n;i++)
        if(a[i]==0)
        delete(a,i,n);
        n--;
        c--;
}
for(int j=0;j<n;j++)
printf("%d ",a[j]);
}
