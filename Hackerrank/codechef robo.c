#include<stdio.h>
main()
{
int t,j=0,n,i,k=0;
char *s;
scanf("%d",&t);
int r[t];
while(k<t)
{
scanf("%s",&s);
n=sizeof(s);
for(i=0;i<n;i++)
for(j=0;j<n;j++)
{
if(s[i]!='.'&&s[j]!='.')
{
if(s[i]+i==j+s[j]||s[i]+i==j-s[j]||i-s[i]==j-s[j]||i-s[i]==j+s[j])
r[k]=1;
}
else
r[k]=0;
}
k++;
}
for(k=0;k<t;k++)
if(r[k]==0)
printf("safe\n");
else
printf("unsafe\n");
}
