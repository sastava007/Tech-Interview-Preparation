#include<stdio.h>
#include<string.h>
int check(char *a)
{
char *b=strrev(a);
if(strcmp(a,b)==0)
return 1;
else
return 0;
}

main()
{
int min=100,max=0;
char s[100];
gets(s);
int i,j;
for(i=0;s[i]!='\0';i++)
{
char t[20];
for(j=0;s[j]!=' '&&s[j]!='\0';j++)
{
t[j]=s[i];
i++;
}
if(check(t)==1)
{
if(strlen(t)<=min)
min=strlen(t);
if(strlen(t)>=max)
max=strlen(t);
}
}
printf("min=%d   max=%d",min,max);
}
