#include<stdio.h>
main()
{
int a[5][5]={{0, 1, 1, 0, 1},
                {1, 1, 0, 1, 0},
                {0, 1, 1, 1, 0},
                {1, 1, 1, 1, 0},
                {1, 1, 1, 1, 1}};
int s[6][5],k=0,l=0,max=0,i,j;
while(k<5&&l<5)
{
int c=0;
for(int i=0;i<=k;i++)
for(int j=0;j<=l;j++)
if(a[i][j]!=1)
c++;
if(c==0)
s[i][j]=k;
else
s[i][j]=0;
k++;
l++;
}
for(int x=0;x<6;x++)
for(int y=0;y<5;y++)
if(s[x][y]>max)
max=s[x][y];
printf("\n%d",max);
}


