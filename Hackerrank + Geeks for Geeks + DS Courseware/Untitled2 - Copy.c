#include<stdio.h>
main()
{
int x=4,y=0,z;
while(x>=0)
{
    x--;
    y++;
    if(x==y)
       continue;
       else
        printf("\n%d%d",x,y);

}
}
