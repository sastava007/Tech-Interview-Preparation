#include<stdio.h>
#include<math.h>
main()
{
int i,a[8],max=0,j,sub[8];
for(i =0;i<8;i++)
{
scanf("%d",&a[i]);
sub[i]=-1;
}

for(i =0;i<8;i++)
{
int s=0;
for(j=i;j<8;j++)
{
s+=a[j];
if(s>max)
{
max=s;
sub[j]=j;
}
}
}
for(i =0;i<8;i++)
    if(sub[i]!=-1)
    printf("%d",sub[i]);
printf("\n%d",max);
}

