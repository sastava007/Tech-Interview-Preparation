int s=0;
#include<stdio.h>
int fun(int a){
if(a==1)
return a;
s=a+fun(a-1);
return s;
}

main()
{
int a=3;
printf("%d",fun(a));

}
