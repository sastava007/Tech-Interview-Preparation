#include<stdio.h>
main()
{
int n;
scanf("%d",&n);
for(int i=0;i<n;i++)
{
int a=65;
for(int j=0;j<n;j++)
{

    if(i+j>=n)
        printf(" ");
    else
       {
    printf("%c",a);
    a++;}
}
if(i==0)
    a=a-2;
else
    a=a-1;
     int t=i;
    while(t!=0){printf(" ");t--;}
for(int k=0;k<n-i-1;k++)
{

    printf("%c",a);
    a--;
}
printf("\n");
}
}
