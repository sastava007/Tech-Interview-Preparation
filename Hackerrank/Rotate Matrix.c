#include<stdio.h>
void rotate(int a[4][4],int m,int n)
{
int i,k=0,l=0,p,c;
while(k<m && l<n)
{
    if(k+1==m||l+1==n)
        break;
p=a[k+1][i];
for(i=l;i<n;i++)
{
c=a[k][i];
a[k][i]=p;
p=c;
}
k++;
for(i=k;i<m;i++)
{
c=a[i][n-1];
a[i][n-1]=p;
p=c;
}
n--;
if(k<m)
{
for(i=n-1;i>=l;i--)
{
c=a[m-1][i];
a[m-1][i]=p;
p=c;
}
m--;
}
if(l<n)
{
for(i=m-1;i>=k;i--)
{
c=a[i][l];
a[i][l]=p;
p=c;
}
l++;
}

}
for(int x=0;x<4;x++)
for(int y=0;y<4;y++)
printf("%d ",a[x][y]);

}
main()
{
int a[4][4]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16},m=4,n=4;
rotate(a,m,n);
}
