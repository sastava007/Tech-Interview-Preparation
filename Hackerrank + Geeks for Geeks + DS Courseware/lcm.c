#include<stdio.h>
int lcm(int n,int *a)
{
    int i=1,c=0;
    while(1)
    {
        for(int j=0;j<n;j++)
            if(!(i%a[j]==0))
            c++;
            if(c!=0)
            {
             return i;
             break;
            }
        i++;
    }
}
main()
{
int arr[4]={1,2,3,4};
printf("%d",lcm(4,arr));


}
