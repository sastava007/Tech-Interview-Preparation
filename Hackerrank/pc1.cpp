#include<bits/stdc++.h>
using namespace std;




int main()
{
  int n,i,j;
  cin>>n;
  int a[n],s[n],c=0;
  for(i=0;i<n;i++)
    cin>>a[i];
    s[0]=1;
    sort(a,a+n);

  for(i=1;i<n;i++)
  {
      if(a[i]>a[i-1])
        s[i]=(s[i-1]+1);
      else if(a[i]==a[i-1]&&(s[i-1]-1)!=0)
        s[i]=s[i-1]-1;
      else if(a[i]==a[i-1])
        s[i]=s[i-1];
  }
  for(i=0;i<n;i++)
  {
      c+=s[i];
  }
  cout<<c;
  return 0;
}
