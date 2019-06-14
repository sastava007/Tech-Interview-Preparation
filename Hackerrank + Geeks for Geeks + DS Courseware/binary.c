#include<stdio.h>
main()
{
for(int i=0;i<3;++i)
{
    int c=1;
    for(int j=0;j<3;j++)
    {
      if(i+j>=2)
        {
          printf("%d",c);
          c++;
        }
        else
        printf(" ");
    }
        for(int k=0;k<i;k++)
          {
           printf("%d",c-2);
           c--;
          }
    printf("\n");
}


}
