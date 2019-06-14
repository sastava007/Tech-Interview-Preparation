#include<stdio.h>
main()
{
for(int i=0;i<5;i++)
{
    int a=65;
    for(int j=0;j<5;j++)
    {
        if(j>=i)
         {
           printf("%c",a);
           a++;
         }
         else
         printf(" ");
    }
    a=a-2;
   for(int k=5;k>i+1;k--)
   {
       printf("%c",a);
       a--;
   }
   printf("\n");
}
}
