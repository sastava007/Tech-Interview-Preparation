#include<stdio.h>
main()
{
int a[10]={1,3,5,3,7,1,5,1,5,1},f[10]={-1},res[10],max=0;
for(int i=0;i<10;i++)
{
int c=1;
for(int j=i+1;j<10;j++)
if(a[i]==a[j])
{
c++;
a[j]=0;
}
if(a[i]!=0)
f[i]=c;
}
/*for(int k=0;k<10;k++)
if(a[k]!=0)
printf("Frequency of %d is %d\n",a[k],f[k]);
*/
for(int k=0;k<10;k++)
    if(f[k]!=-1)
{
    if(f[k]>max)
        max=f[k];
}
}
