#include<stdio.h>
#include<math.h>
int length(int a)
{
    int q=a,c=0;
    while(q!=0)
    {
        q/=10;
        c++;
    }
    return c;
}
int rnum(int a,int n,int d)
{
    int b=pow(10,d);
   int r=a%b;
  return r;
}
int lnum(int a,int n,int d)
{
   int l=a/pow(10,d);
  return l;
}
main()
{
    int p,q,l=0,r=0,n,s,d,c=0;
    scanf("%d%d",&p,&q);
    for(int i=p;i<=q;i++)
    {
      s=i*i;
      d=length(i);
      n=length(s);
      r=rnum(s,n,d);
      l=lnum(s,n,d);
      if(r+l==i)
      {
          printf("%d ",i);
          c++;
      }
    }
    if(c==0)
    printf("INVALID RANGE");
}

