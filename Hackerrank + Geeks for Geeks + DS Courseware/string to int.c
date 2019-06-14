#include<stdio.h>
#include<math.h>
#include<string.h>
main()
{
char s[100];
scanf("%s",s);
int n=strlen(s),a=0;
for(int i=0;i<n;i++)
{
    //int num=s[i]-48;
a=a+((int)s[i])*pow(10,n-1-i);
}
printf("%d",a);

}
