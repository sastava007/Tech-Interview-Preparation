#include<stdio.h>
main()
{
int a[8],i,f[8],j;
for(i=0;i<8;i++)
scanf("%d",&a[i]);

for(i=0;i<8;i++)
{
    int c=1;
for(j=i+1;j<8;j++)
    if(a[i]==a[j])
    {
        c++;
        f[j]=0;
    }
if(f[i]!=0)
f[i]=c;
}
  for(i=0;i<8;i++)
    if(f[i]!=0)
    printf("Frequency of %d is %d\n",a[i],f[i]);

}
