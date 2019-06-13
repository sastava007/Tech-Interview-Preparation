#include<stdio.h>
main()
{
int n,q,c=0,hexa=0;
scanf("%d",&n);
q=n;
while(q!=0)
{
q=q/10;
c++;
}
int temp,rem;
char arr[c];
for(int i=0;i<c;i++)
{
rem =temp%16;
temp=temp/16;
if(rem==10)
arr[i]='A';
else if(rem==11)
arr[i]='B';
else if(rem==12)
arr[i]='C';
else if(rem==13)
arr[i]='D';
else if(rem==14)
arr[i]='E';
else if(rem==15)
arr[i]='F';
else
arr[i]=rem;
}
for(int x=c-1;x>=0;x--)
printf("%s",arr[x]);

}
