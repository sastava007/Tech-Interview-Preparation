#include<bits/stdc++.h>
using namespace std;
main()
{
    int n,q,i,target,s;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
    cin>>a[i];
    cin>>q;
    while(q--)
    {
       s=0;
       cin>>target;
       for(i=0;i<n;i++)
       {
           s+=a[i];
           if(s>=target)
           {
               cout<<i+1<<endl;
               break;
           }
       }
    }
}

