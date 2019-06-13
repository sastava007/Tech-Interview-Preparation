#include<stdio.h>
main()
{
char a[5][20]={"Rohit","Avanish","Shikhar","Shikha","Aditya"};
char t[15];
int i,j;
for(int k=0;k<4;k++)
for(i=0;i<4;i++)
{
int n=strlen(a[i]);
int m=strlen(a[i+1]);
for(j=0;j<n-1&&j<m-1;j++)
if(a[i][j]>a[i+1][j])
{
strcpy(t,a[i]);
strcpy(a[i],a[i+1]);
strcpy(a[i+1],t);
}
}
for(i=0;i<5;i++)
printf("%s ",a[i]);
}
