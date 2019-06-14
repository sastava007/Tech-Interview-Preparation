#include<bits/stdc++.h>
using namespace std;
main()
{
    int n,i,j;
    cin>>n;
    int a[n],f[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        f[i]=0;
    }
    for(i=0;i<n;i++)
    {
        int t=1;
        for(j=i+1;j<n;j++)
         if(a[i]==a[j]&&a[j]!=1e7)
         {
             t++;
             a[j]=1e7;
         }
         f[i]=t;
    }
    for(i=0;i<n;i++)
    {
        if(a[i]!=1e7 && f[i]!=0)
            cout<<"Frequencey of "<<a[i]<<" is "<<f[i]<<endl;
    }
}
