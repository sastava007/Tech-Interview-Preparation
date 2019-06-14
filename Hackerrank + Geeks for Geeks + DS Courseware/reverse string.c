#include<stdio.h>
main()
{
    int c=0;
char s[100];
gets(s);
for(int i=0;s[i]!='\0';i++)
    c++;
for(int i=c-1;i>=0;i--)
printf("%c",s[i]);




}
