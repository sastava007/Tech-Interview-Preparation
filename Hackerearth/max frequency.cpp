#include<bits/stdc++.h>
using namespace std;
main()
{
    int n,i,c=1,max=0,max_ele;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
    cin>>a[i];
    sort(a,a+n);
    for(i=0;i<n-1;i++)
    {
        if(i!=0&&a[i]==a[i-1])
          c=c;
          else
          c=1;
        if(a[i]==a[i+1])
        {
            c++;
            if(c>max)
              {
                  max=c;
                  max_ele=a[i];
              }
        }
    }
    cout<<max_ele;
}


