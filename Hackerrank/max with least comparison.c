#include<stdio.h>
#include<time.h>
main()
{
clock_t start,end;
start=clock();
int a[5],i,max=0;
for(i=0;i<5;i++)
scanf("%d",&a[i]);
for(i=0;i<4;i++)
{
int t=a[i]>a[i+1]?a[i]:a[i+1];
if(t>max)
max=t;
}
printf("%d",max);
end=clock();
double time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
printf("%lf",time_used);
}
