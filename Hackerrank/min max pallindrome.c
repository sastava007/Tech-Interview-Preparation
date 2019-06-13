#include<stdio.h>
#include<string.h>
int pallindrome(char *s)
{
char *t=strrev(s);
if(strcmp(s,t)==0)
return strlen(s);
else
return 0;
}

main()
{
char *s="wow I speak abccba",t[10];
int n=strlen(s),i=0,j=0,min=1,max=1;
while(s[i]!='\0')
{
   while(s[j]!=' '&& j<n)
    {
      t[j]=s[j];
      j++;
      i++;
    }
   if(pallindrome(t)<=min)
   min=pallindrome(t);
   if(pallindrome(t)>=max)
   max=pallindrome(t);
   i++;
   j=i;
}

printf("min=%d max=%d",min,max);

}
