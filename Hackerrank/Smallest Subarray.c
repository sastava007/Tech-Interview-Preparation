#include<stdio.h>
main()
{
int arr[5] = {1, 10, 5, 2, 7},min=2580,t;
for(int i=0;i<5;i++)
{
int sum=0;
for(int j=i;j<5;j++)
{
sum+=arr[i]+arr[j];
if(sum>10)
{
t=j-i+1;
if(t<min)
min=t;

}
}
}
printf("%d",min);

}
