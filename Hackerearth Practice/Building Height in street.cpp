#include<bits/stdc++.h>
using namespace std;
main()
{
    int s,n,r,c,i,h,max;
    cin>>s;
    while(s--)
    {
      c=1;
      cin>>n>>r;
      long long int h[n];
      for(i=0;i<n;i++)
         cin>>h[i];
         max=h[0];
        for(i=1;i<n;i++)
        if(h[i]>h[i-1]&&h[i]>max)
           {
               c++;
               max=h[i];
           }
        cout<<r*c<<endl;
    }

}
