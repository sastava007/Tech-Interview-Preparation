#include<stdio.h>
#include<string.h>
int factorial(int n)
{
int p=1;
for(int i=1;i<=n;i++)
p*=i;
return p;
}

main()
{
int n,i;
char a[10][20]={"Mady","hash_include","sastava007","shakshi119","shikha001","pallo","the_unknown","sudo_bug","newton003","harshal"};
char *s;
printf("Enter Your Username\n");
scanf("%s",s);
for(i=0;i<10;i++)
{
if(strcmp(s,a[i])==0)
{
printf("Enter a number to find factorial\n");
scanf("%d",&n);
printf("%d\n",factorial(n));
break;
}
}
if(i==10)
printf("Access Denied\n");

}
