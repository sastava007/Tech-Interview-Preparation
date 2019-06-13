#include<iostream>
#include<bits/stdc++.h>
using namespace std;
main()
{
    int c=0,j=0,n,i;
    cin>>n;
    string s[n],r[n],t;
    for(i=0;i<n;i++)
    cin>>s[i];
    while(j<n)
    {  c=0;
      t=s[j];
    do
    {
       if(s[j].compare(t)>0)
       {
           r[j]=s[j];
           c++;
           break;
       }
    } while(next_permutation(s[j].begin(),s[j].end()));
    if(c==0)
    r[j]="no answer";
    j++;
    }
    for (i = 0; i < n; i++)
    cout<<r[i]<<endl;
}
