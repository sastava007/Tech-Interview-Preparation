#include<bits/stdc++.h>
using namespace std;
main()
{
    string s;
    cin>>s;
    int i,n=s.length();
    int a[n];
    memset(a,-1,n);
    for(i=0;i<n;i++)
    {
        if(a[s[i]]==-1)
            a[s[i]]=i;
        else
           a[s[i]]=-2;
    }
    for(i=0;i<n;i++)
        if(a[s[i]]!=-2)
        {
            cout<<s[i];
            break;
        }
}

