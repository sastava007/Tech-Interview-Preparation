#include<stdio.h>
#include<string.h>
main()
{
    char s[82],t;
    int i,j,c=0;
    gets(s);
    float n=strlen(s);
    for(i=0;i<n-1;i++)
    {
        if(s[i]==' ')
        {
            for(j=i;j<n-1;j++)
            {
                t=s[j];
                s[j]=s[j+1];
                s[j+1]=t;
            }
            n--;
        }
    }
    float size=sqrt(n);
    int a=floor(size);
    int b=ceil(size);

    if(a*b<n)
    a=a+1;
    char ch[a][b];
    for(i=0;i<a;i++)
        for(j=0;j<b;j++)
        ch[i][j]='\0';

    for(i=0;i<a;i++)
        for(j=0;j<b;j++)
        {   if(c<n)
           {
                  ch[i][j]=s[c];
                   c++;
           }
        }
        c=0;

    for(j=0;j<b;j++)
      {
          for(i=0;i<a;i++)
            {     if(ch[i][j]!='\0')
                  printf("%c",ch[i][j]);

           }
            printf(" ");
      }
}
