#include<stdio.h>
main()
{
int c=1,d=3;
for(int i=0;i<7;i++)
{
    for(int j=0;j<7;j++)
{
    c=c-1;
if(i==j||i+j==6)
{

    if(i<=3)
    {
        printf("%d",c);
        c++;
    }
    else if(i>3)
    {
        printf("%d",d);
        d--;
    }
}
else
    printf(" ");
}
printf("\n");

}

}



