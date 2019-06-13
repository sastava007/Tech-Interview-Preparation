#include<stdio.h>
main()
{
int n;
scanf("%d",&n);
for(int i=0;i<n;i++)
{
int c=10,s=i,u=1;
for(int j=0;j<=i;j++)
{
printf("%d",(c-s)%10);
s--;
}
for(int k=0;k<i;k++)
{
printf("%d",(c-u)%10);
u++;
}

printf("\n");
}


}
